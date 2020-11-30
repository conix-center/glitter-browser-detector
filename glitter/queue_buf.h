#ifndef _QUEUE_BUF_
#define _QUEUE_BUF_

#define BUF_SIZE    16

struct queue_buf {
    int idx;
    uint8_t buf[BUF_SIZE];
};

static inline uint8_t qb_add(struct queue_buf *qb, uint8_t in) {
    uint8_t res = qb->buf[qb->idx];
    qb->buf[qb->idx] = in;
    qb->idx = (qb->idx + 1) % BUF_SIZE;
    return res;
}

static inline void qb_stats(struct queue_buf *qb, uint8_t *max, uint8_t *min) {
    *max = 0;
    *min = 255;
    for (int i = 0; i < BUF_SIZE; i++)
    {
        *max = (qb->buf[i] > *max) ? qb->buf[i] : *max;
        *min = (qb->buf[i] < *min) ? qb->buf[i] : *min;
    }
    *max = (*max != 0) ? *max : 255;
    *min = (*min != 255) ? *min : 0;
}

#endif

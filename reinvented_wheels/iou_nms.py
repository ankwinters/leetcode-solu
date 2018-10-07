#!/usr/bin/env python3


def compute_iou(box1, box2):
    x1, y1, x2, y2 = box1
    x3, y3, x4, y4 = box2
    w1, h1 = abs(x2-x1), abs(y2-y1)
    w2, h2 = abs(x4-x3), abs(y4-y3)
    # Intersection box
    w_in = w1 + w2 - abs(x3-x1)
    h_in = h1 + h2 - abs(y3-y1)
    if w_in > 0 and h_in > 0:
        return (w_in*h_in) / (w1*h1 + w2*h2 - w_in*h_in)
    else:
        return 0


def nms(box_confi_list, thresh=0.5):
    """
    :param box_confi_list: [box1, box2....],
            box is a tuple of(x1,y1,x2,y2,confi)
    :param thresh: iou thresh
    :return: keep_box_list
    """
    keep_box_list = []
    s_box_confi_list = sorted(box_confi_list, key=lambda b: b[4], reverse=True)

    for i in range(len(s_box_confi_list)):
        box = s_box_confi_list[i]
        if len(box) != 5:
            continue
        keep_box_list.append(box)
        for j in range(i+1, len(s_box_confi_list)):
            box2 = s_box_confi_list[j]
            iou = compute_iou(box[:-1], box2[:-1])
            # Suppress
            if iou > thresh:
                s_box_confi_list[j] = ()

    return keep_box_list


if __name__ == '__main__':
    l2 = [(2, 1, 3, 4, 0.8), (3, 4, 5, 6, 0.9)]
    nms(l2, 0)

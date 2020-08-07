import numpy as np
from struct import unpack
import matplotlib.pyplot as plt
from matplotlib.ticker import MultipleLocator


def ReadImg(filepath):
    with open(filepath, 'rb') as f:
        _, img_num, h, w = unpack('>4I', f.read(16))
        img = np.fromfile(f, dtype=np.uint8).reshape(img_num, h * w)
        return img

def ReadLable(filepath):
    with open(filepath, 'rb') as f:
        _, _num = unpack('>2I', f.read(8))
        label = np.fromfile(f, dtype=np.uint8).reshape(_num, 1)
        return label

def KNN(train, test, test_num, train_label, k):
    test_predict = np.zeros([test_num, 1])
    for test_id in range(test_num):
        t_img = test[test_id]
        diff = np.sqrt(np.sum(np.square(train - t_img), axis=1))
        index = np.argsort(diff)[:k] 
        k_label = train_label[index].reshape([1, -1])[0].astype(np.int64)
        test_predict[test_id] = np.argmax(np.bincount(k_label))
    return test_predict

def myMain():
    # 读取
    train_img = ReadImg('Data/train-images.idx3-ubyte')
    train_label = ReadLable('Data/train-labels.idx1-ubyte')
    test_img = ReadImg('Data/t10k-images.idx3-ubyte')
    test_label = ReadLable('Data/t10k-labels.idx1-ubyte')


    train_img = train_img.astype(np.float32)
    train_label = train_label.astype(np.float32)
    test_img = test_img.astype(np.float32)
    test_label = test_label.astype(np.float32)

    accuracy = []
    train_num = 2000
    test_num = 500
    _range = 16
    for i in range(1, _range):
        result = KNN(test_img[:train_num, :], test_img[train_num:train_num + test_num, :], test_num, test_label[:train_num, :], i)
        # 计算准确率
        matches = result == test_label[train_num:train_num + test_num, :]
        correct = np.count_nonzero(matches)
        ans = float(correct) / float(test_num)
        accuracy.append(1 - ans)
        print("k = %d \t accuracy:%.2f" % (i, ans * 100))

    x1 = np.arange(1, _range)
    plt.plot(x1, accuracy, linewidth = 1, color = 'k', marker = 'o', markerfacecolor = 'k', markersize = 2)
    plt.xlabel('K')
    plt.ylabel('Misclassification Rate')

    x_major_locator = MultipleLocator(1)
    ax = plt.gca()
    ax.xaxis.set_major_locator(x_major_locator)
    plt.xlim(-0.5, _range + 1)
    plt.legend()
    plt.show()
    

if __name__ == '__main__':
    myMain()
import numpy as np
import csv


def Load_data(file):
    """
    :param file: 文件
    
    :return
        train_data：     训练数据集
        train_classes：  训练数据集的分类
        test_data：      测试数据集
        test_classes：   测试数据集的分类
        label：          分类
    """
    data_mat = []
    with open(file) as file_obj:
        voice_reader = csv.DictReader(file_obj)
        list_class = []
        label = list(voice_reader.fieldnames)
        num = len(label) - 1

        for line in voice_reader.reader:
            data_mat.append(line[:num])
            gender = 1 if line[-1] == 'male' else 0
            list_class.append(gender)

        # 求特征的平均值
        data_mat = np.array(data_mat).astype(float)
        count_vector = np.count_nonzero(data_mat, axis=0)
        sum_vector = np.sum(data_mat, axis=0)
        mean_vector = sum_vector / count_vector

        # 用平均值填充缺失数据
        for row in range(len(data_mat)):
            for col in range(num):
                if data_mat[row][col] == 0.0:
                    data_mat[row][col] = mean_vector[col]

        # 离散化
        min_vector = data_mat.min(axis=0)
        max_vector = data_mat.max(axis=0)
        diff_vector = max_vector - min_vector
        diff_vector /= 9
        new_data_set = []
        for i in range(len(data_mat)):
            line = np.array((data_mat[i] - min_vector) / diff_vector).astype(int)
            new_data_set.append(line)

        # 区分训练集、测试集
        test_set = list(range(len(new_data_set)))
        train_set = []
        for i in range(2000):
            random_index = int(np.random.uniform(0, len(test_set)))
            train_set.append(test_set[random_index])
            del test_set[random_index]

        # 训练数据集
        train_data = []
        train_classes = []
        for index in train_set:
            train_data.append(new_data_set[index])
            train_classes.append(list_class[index])

        # 测试数据集
        test_data = []
        test_classes = []
        for index in test_set:
            test_data.append(new_data_set[index])
            test_classes.append(list_class[index])

    return train_data, train_classes, test_data, test_classes, label


def Naive_Bayes(train_matrix, list_classes):
    """
    :param train_matrix:    训练样本矩阵
    :param list_classes:    训练样本分类向量
    :return:
        p_1_class               任一样本分类为1的概率  
        p_feature, p_1_feature  给定类别的情况下特征所有取值的概率
    """
    num_train_data = len(train_matrix)
    num_feature = len(train_matrix[0])
    p_1_class = sum(list_classes) / float(num_train_data)

    n = 10
    list_classes_1 = []
    train_data_1 = []

    for i in list(range(num_train_data)):
        if list_classes[i] == 1:
            list_classes_1.append(i)
            train_data_1.append(train_matrix[i])

    train_data_1 = np.matrix(train_data_1)
    p_1_feature = {}
    for i in list(range(num_feature)):
        feature_values = np.array(train_data_1[:, i]).flatten()
        feature_values = feature_values.tolist() + list(range(n))
        p = {}
        count = len(feature_values)
        for value in set(feature_values):
            p[value] = np.log(feature_values.count(value) / float(count))
        p_1_feature[i] = p

    p_feature = {}
    train_matrix = np.matrix(train_matrix)
    for i in list(range(num_feature)):
        feature_values = np.array(train_matrix[:, i]).flatten()
        feature_values = feature_values.tolist() + list(range(n))
        p = {}
        count = len(feature_values)
        for value in set(feature_values):
            p[value] = np.log(feature_values.count(value) / float(count))
        p_feature[i] = p

    return p_feature, p_1_feature, p_1_class


def Classifier(test_vector, p_feature, p_1_feature, p_1_class):
    sum = 0.0
    for i in list(range(len(test_vector))):
        sum += p_1_feature[i][test_vector[i]]
        sum -= p_feature[i][test_vector[i]]
    p1 = sum + np.log(p_1_class)
    p0 = 1 - p1
    if p1 > p0:
        return 1
    else:
        return 0


def test_bayes():
    file = 'data/voice.csv'
    train_data, train_classes, test_data, test_classes, label = Load_data(file)

    p_feature, p_1_feature, p_1_class = Naive_Bayes(train_data, train_classes)

    count_1 = 0.0
    count_0 = 0.0
    correct_count_1 = 0.0
    correct_count_0 = 0.0

    for i in list(range(len(test_data))):
        test_vector = test_data[i]
        result = Classifier(test_vector, p_feature, p_1_feature, p_1_class)
        if test_classes[i] == 1:
            if result == test_classes[i]:
                correct_count_1 += 1
            count_1 += 1
        if test_classes[i] == 0:
            if result == test_classes[i]:
                correct_count_0 += 1
            count_0 += 1
    print("男性声音正确率为：%f" % (correct_count_1 / count_1))
    print("女性声音正确率为：%f" % (correct_count_0 / count_0))


test_bayes()
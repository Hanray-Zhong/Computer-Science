package hust.cs.javacourse.search.run;

import hust.cs.javacourse.search.*;
import hust.cs.javacourse.search.index.AbstractDocument;
import hust.cs.javacourse.search.index.impl.Document;
import hust.cs.javacourse.search.index.impl.DocumentBuilder;
import hust.cs.javacourse.search.index.impl.Index;
import hust.cs.javacourse.search.index.impl.IndexBuilder;

import java.io.IOException;
import java.util.Scanner;

public class TestBuildIndex {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);

        DocumentBuilder documentBuilder = new DocumentBuilder();
        IndexBuilder indexBuilder = new IndexBuilder(documentBuilder);

        System.out.println("Input path: ");
        // D:\文档\学习\JAVA\Java实验1\CS1703_U201714607_钟子琛_实验一\功能测试数据集
        // D:\文档\学习\JAVA\Java实验1\CS1703_U201714607_钟子琛_实验一\真实测试数据集
        String path = scanner.nextLine();
        path.replace('\n', '\0');
        Index index = (Index) indexBuilder.buildIndex(path);
        index.optimize();
        System.out.println(index.toString());
    }
}

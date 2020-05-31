package hust.cs.javacourse.search.index;


import hust.cs.javacourse.search.index.impl.DocumentBuilder;

import java.io.IOException;

/*
AbstractIndexBuilder是索引构造器的抽象父类 需要实例化一个具体子类对象完成索引构造的工作
 */
public abstract class AbstractIndexBuilder
        extends java.lang.Object
{
    // 字段
    protected AbstractDocumentBuilder docBuilder = new DocumentBuilder();
    protected int docId = 1;

    // 构造函数
    public AbstractIndexBuilder() { }
    public AbstractIndexBuilder(AbstractDocumentBuilder docBuilder) {
        this.docBuilder = docBuilder;
    }

    // 方法
    public abstract AbstractIndex buildIndex(java.lang.String rootDirectory) throws IOException;

}

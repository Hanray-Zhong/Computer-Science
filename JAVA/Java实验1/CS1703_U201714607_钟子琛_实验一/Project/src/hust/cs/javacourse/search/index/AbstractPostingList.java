package hust.cs.javacourse.search.index;

import java.util.ArrayList;
import java.util.List;

/*
AbstractPostingList是所有PostingList对象的抽象父类.
 */
public abstract class AbstractPostingList
        extends java.lang.Object
        implements FileSerializable
{
    // 字段
    public List<AbstractPosting> list = new ArrayList<>();

    // 方法
    public abstract void add(AbstractPosting posting);
    public abstract java.lang.String toString();
    public abstract void add(java.util.List<AbstractPosting> postings);
    public abstract AbstractPosting get(int index);
    public abstract int indexOf(AbstractPosting posting);
    public abstract int indexOf(int docId);
    public abstract boolean contains(AbstractPosting posting);
    public abstract void remove(int index);
    public abstract void remove(AbstractPosting posting);
    public abstract int size();
    public abstract void clear();
    public abstract boolean isEmpty();
    public abstract void sort();

}

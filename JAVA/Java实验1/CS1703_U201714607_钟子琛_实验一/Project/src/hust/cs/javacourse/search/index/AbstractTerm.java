package hust.cs.javacourse.search.index;

import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.lang.*;

/*
AbstractTerm是Term对象的抽象父类.
 */
public abstract class AbstractTerm
        extends Object
        implements Comparable<AbstractTerm>, FileSerializable
{
    // 字段
    protected String content = new String();

    // 构造函数
    public AbstractTerm() { }
    public AbstractTerm(String content) {
        this.content = new String(content);
    }

    // 方法
    @Override
    public int hashCode()
    {
        int result = 17;
        result = 31 * result + content.hashCode();
        return result;
    }
    public abstract boolean equals(Object obj);
    public abstract String toString();
    public abstract String getContent();
    public abstract void setContent(String content);
    public abstract int compareTo(AbstractTerm o);

}

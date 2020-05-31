package hust.cs.javacourse.search.index;

import java.io.IOException;

/*
定义文件序列化接口
 */
public interface FileSerializable extends java.io.Serializable
{
    /*
    从二进制文件读
     */
    void readObject(java.io.ObjectInputStream in) throws IOException, ClassNotFoundException;
    /*
    写到二进制文件
     */
    void writeObject(java.io.ObjectOutputStream out) throws IOException;
}

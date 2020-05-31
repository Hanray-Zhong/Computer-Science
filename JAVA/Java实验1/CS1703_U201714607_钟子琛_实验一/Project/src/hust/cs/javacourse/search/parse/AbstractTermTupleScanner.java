package hust.cs.javacourse.search.parse;

import java.io.BufferedReader;
import java.io.IOException;

/*
AbstractTermTupleScanner是AbstractTermTupleStream的抽象子类，
即一个具体的TermTupleScanner对象就是 一个AbstractTermTupleStream流对象，
它利用java.io.BufferedReader去读取文本文件得到一个个三元组TermTuple.
 */
public abstract class AbstractTermTupleScanner extends AbstractTermTupleStream
{
    protected BufferedReader input;

    public AbstractTermTupleScanner() { }
    public AbstractTermTupleScanner(BufferedReader input) {
        this.input = input;
    }

    public void close() throws IOException {
        input.close();
    }
}

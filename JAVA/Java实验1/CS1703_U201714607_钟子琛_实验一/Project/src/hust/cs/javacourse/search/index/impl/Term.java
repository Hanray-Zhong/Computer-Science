package hust.cs.javacourse.search.index.impl;

import hust.cs.javacourse.search.index.AbstractTerm;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

public class Term extends AbstractTerm {
    // 构造函数
    public Term() { }
    public Term(String content) {
        this.content = new String(content);
    }

    @Override
    public boolean equals(Object obj) {
        if (obj.getClass() == Term.class)
            return content.equals(((Term) obj).content);
        return false;
    }

    @Override
    public String toString() {
        return "Term: " + content;
    }

    @Override
    public String getContent() {
        return content;
    }

    @Override
    public void setContent(String content) {
        this.content = new String(content);
    }

    @Override
    public int compareTo(AbstractTerm o) {
        return this.hashCode() - o.hashCode();
    }

    @Override
    public void readObject(ObjectInputStream in) throws IOException, ClassNotFoundException {
        in.readObject();
        in.close();
    }

    @Override
    public void writeObject(ObjectOutputStream out) throws IOException {
        out.writeObject(this);
        out.close();
    }
}

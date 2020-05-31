package hust.cs.javacourse.search.index;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Map;
import java.util.Set;

/*
AbstractIndex是内存中的倒排索引对象的抽象父类.
 */
public abstract class AbstractIndex
        extends java.lang.Object
        implements FileSerializable
{
    // 字段
    protected Map<Integer, String> docIdToDocPathMapping;
    protected Map<AbstractTerm,AbstractPostingList> termToPostingListMapping;

    // 方法
    public abstract java.lang.String toString();
    public abstract int getDocSize();
    public abstract void addDocument(AbstractDocument document);
    public abstract void load(File file) throws IOException, ClassNotFoundException;
    public abstract void save(File file) throws IOException;
    public abstract AbstractPostingList search(AbstractTerm term);
    public abstract Set<AbstractTerm> getDictionaryKey();
    public abstract Map<AbstractTerm,AbstractPostingList> getDictionary();
    public abstract void optimize();
    public abstract String getDocName(int docId);
}

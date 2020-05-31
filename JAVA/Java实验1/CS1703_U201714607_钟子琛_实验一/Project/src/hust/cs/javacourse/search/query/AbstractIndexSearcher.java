package hust.cs.javacourse.search.query;

import hust.cs.javacourse.search.index.AbstractIndex;
import hust.cs.javacourse.search.index.AbstractTerm;
import hust.cs.javacourse.search.index.impl.Index;

import java.io.IOException;

public abstract class AbstractIndexSearcher extends java.lang.Object
{
    public AbstractIndex index = new Index();

    public abstract void open(String indexFile) throws IOException, ClassNotFoundException;
    public abstract AbstractHit[] search(AbstractTerm queryTerm, Sort sorter);
    public abstract AbstractHit[] search(AbstractTerm queryTerm1, AbstractTerm queryTerm2, Sort sorter, AbstractHit.LogicalCombination combine);
}
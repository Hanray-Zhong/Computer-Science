package hust.cs.javacourse.search.query.impl;

import hust.cs.javacourse.search.query.AbstractHit;
import hust.cs.javacourse.search.query.Sort;

import java.util.List;

public class Sorter implements Sort {
    @Override
    public void sort(List<AbstractHit> hits) {

    }

    @Override
    public double score(AbstractHit hit) {
        return 1.0;
    }
}

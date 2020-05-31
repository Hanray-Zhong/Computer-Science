package hust.cs.javacourse.search.query;

import java.util.List;

public interface Sort {
    void sort(List<AbstractHit> hits);
    double score(AbstractHit hit);
}

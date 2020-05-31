import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class WareHouse implements ItemIterator {
    private List<Item> fullPriceItems = new ArrayList<>();
    private List<Item> discountPriceItems = new ArrayList<>();
    List<Item> list = new ArrayList<>();
    Iterator<Item> iterator = list.iterator();

    public WareHouse(List<Item> fullPriceItems, List<Item> discountPriceItems) {
        this.fullPriceItems = new ArrayList<>(fullPriceItems);
        list.addAll(fullPriceItems);
        list.addAll(discountPriceItems);
    }

    @Override
    public Item next() {
        return iterator.next();
    }

    @Override
    public boolean hasNext() {
        return iterator.hasNext();
    }
    public ItemIterator iterator() {
        return iterator;
    }
}

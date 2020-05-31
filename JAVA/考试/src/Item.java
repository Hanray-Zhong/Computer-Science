public abstract class Item implements Cloneable {
    protected String name;    //商品名称
    public Item(String name){ this.name = name; }

    // 计算商品 价格并返回
    public abstract double salePrice();

    @Override
    public Object clone() throws CloneNotSupportedException {
        Item item = (Item)super.clone();
        item.name = new String(this.name);
        return item;
    }
}

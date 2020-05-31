public class FullPriceItem extends Item {
    protected double price;   //商品价格

    public FullPriceItem(String name, double price){
        super(name);
        this.price = price;
    }

    @Override
    public double salePrice() { return price; }

    @Override
    public Object clone() throws CloneNotSupportedException {
        return new FullPriceItem(name, price);
    }
}

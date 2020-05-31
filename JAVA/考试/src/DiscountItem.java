public class DiscountItem extends FullPriceItem {
    private double discount; //商品折扣
    public DiscountItem(String name, double price,double discount){
        super(name, price);
        this.discount = discount;
    }
    @Override
    public double salePrice() {
        return price * discount;
    }

    @Override
    public Object clone() throws CloneNotSupportedException {
        return new DiscountItem(name, price, discount);
    }
}

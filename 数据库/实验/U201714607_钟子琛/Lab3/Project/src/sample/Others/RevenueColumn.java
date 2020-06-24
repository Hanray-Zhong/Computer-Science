package sample.Others;

public class RevenueColumn {
    private String userName;
    private String carId;
    private String rentAmount;
    private String rentDate;

    public RevenueColumn(String userName, String carId, String rentAmount, String rentDate) {
        this.userName = userName;
        this.carId = carId;
        this.rentAmount = rentAmount;
        this.rentDate = rentDate;
    }

    //get
    public String getUserName() {
        return userName;
    }

    public String getCarId() {
        return carId;
    }

    public String getRentAmount() {
        return  rentAmount;
    }

    public String getRentDate() {
        return rentDate;
    }

    //set
    public void setuserName(String userName) {
        this.userName = userName;
    }

    public void setcarId(String carId) {
        this.carId = carId;
    }

    public void setrentAmount(String rentAmount) {
        this.rentAmount = rentAmount;
    }

    public void setrentDate(String rentDate) {
        this.rentDate = rentDate;
    }

}

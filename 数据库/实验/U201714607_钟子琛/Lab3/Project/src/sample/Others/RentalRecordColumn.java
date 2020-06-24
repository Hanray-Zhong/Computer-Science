package sample.Others;

public class RentalRecordColumn {
    private String userId;
    private String userName;
    private String carType;
    private String carId;
    private String rentDate;
    private String returnDate;

    public RentalRecordColumn(String userId, String userName, String carType, String carId, String rentDate, String returnDate) {
        this.userId = userId;
        this.userName = userName;
        this.carType = carType;
        this.carId = carId;
        this.rentDate = rentDate;
        this.returnDate = returnDate;
    }

    //get
    public String getUserId() {
        return userId;
    }

    public String getUserName() {
        return userName;
    }

    public String getCarType() {
        return carType;
    }

    public String getCarId() {
        return carId;
    }

    public String getRentDate() {
        return rentDate;
    }

    public String getReturnDate() {
        return returnDate;
    }
    //set
    public void setuserId(String userId) {
        this.userId = userId;
    }

    public void setuserName(String userName) {
        this.userName = userName;
    }

    public void setcarType(String carType) {
        this.carType = carType;
    }

    public void setcarId(String carId) {
        this.carId = carId;
    }

    public void setrentDate(String rentDate) {
        this.rentDate = rentDate;
    }

    public void setreturnDate(String returnDate) {
        this.returnDate = returnDate;
    }

}

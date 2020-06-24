package sample.Others;

public class RepairRecordColumn {
    private String carType;
    private String carId;

    public RepairRecordColumn(String carType, String carId) {
        this.carType = carType;
        this.carId = carId;
    }

    //get
    public String getCarType() {
        return carType;
    }

    public String getCarId() {
        return carId;
    }

    //set
    public void setcarType(String carType) {
        this.carType = carType;
    }

    public void setcarId(String carId) {
        this.carId = carId;
    }

}

package sample.Others;

public class BrColumn {
    private String GHBH;
    private String BRMC;
    private String GHTime;
    private String HZLB;

    public BrColumn(String GHBH, String BRMC,String GHTime,String HZLB) {
        this.GHBH = GHBH;
        this.BRMC = BRMC;
        this.GHTime = GHTime;
        this.HZLB = HZLB;
    }

    //get
    public String getGHBH() {
        return GHBH;
    }

    public String getBRMC() {
        return BRMC;
    }

    public String getGHTime() {
        return GHTime;
    }

    public String getHZLB() {
        return HZLB;
    }

    //set
    public void setGHBH(String GHBH) {
        this.GHBH = GHBH;
    }

    public void setBRMC(String BRMC) {
        this.GHBH = BRMC;
    }

    public void setGHTime(String GHTime) {
        this.GHBH = GHTime;
    }

    public void setHZLB(String HZLB) {
        this.GHBH = HZLB;
    }
}

package sample.Others;

public class SrColumn {
    private String KSMC;
    private String YSBH;
    private String YSMC;
    private String HZLB;
    private int GHRC;
    private double SRHJ;
    private boolean isVisited = false;

    public SrColumn(String KSMC, String YSBH, String YSMC, String HZLB, int GHRC, double SRHJ) {
        this.KSMC = KSMC;
        this.YSBH = YSBH;
        this.YSMC = YSMC;
        this.HZLB = HZLB;
        this.GHRC = GHRC;
        this.SRHJ = SRHJ;
    }


    public String getKSMC() {
        return KSMC;
    }

    public void setKSMC(String KSMC) {
        this.KSMC = KSMC;
    }

    public String getYSBH() {
        return YSBH;
    }

    public void setYSBH(String YSBH) {
        this.YSBH = YSBH;
    }

    public String getYSMC() {
        return YSMC;
    }

    public void setYSMC(String YSMC) {
        this.YSMC = YSMC;
    }

    public String getHZLB() {
        return HZLB;
    }

    public void setHZLB(String HZLB) {
        this.HZLB = HZLB;
    }

    public int getGHRC() {
        return GHRC;
    }

    public void setGHRC(int GHRC) {
        this.GHRC = GHRC;
    }

    public double getSRHJ() {
        return SRHJ;
    }

    public void setSRHJ(int SRHJ) {
        this.SRHJ = SRHJ;
    }

    public boolean isVisited() {
        return isVisited;
    }

    public void setVisited(boolean visited) {
        isVisited = visited;
    }
}

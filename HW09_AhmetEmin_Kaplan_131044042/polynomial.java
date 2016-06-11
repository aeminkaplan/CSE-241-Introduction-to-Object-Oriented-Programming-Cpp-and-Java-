package hw09_ahmetemin_kaplan_131044042;


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author aek
 */
public class polynomial {

    private double[] polynom;

    private int psize = 0;

    
    /**
     * Parametre olarak aldigi indexteki katsayi degerini return eder
     * @param n-int
     * @return double
     */
    public double getIndex(int n) {
       
        
        if(n>=0 && n<=getSize()-1)
            return polynom[n];
        
        else
        {
            System.out.printf("Hatali indexe erismeye calisiyorsunuz!\n");
            return -9999999.0;
        }
    }

    
    
    /**
     *Parametre olarak aldigi double[] dizisinin degerlerini katsayilari sakladigi diziye atayarak butun
     * katsayilari set eder.
     * @param param-double[]
     */
    public void set_all_coefs(double[] param) {

        polynom = new double[param.length];

        for (int i = 0; i < param.length; ++i) {
            polynom[i] = param[i];
        }

        psize = param.length;

    }

    
    
    /**
     *Katsayilari saklamak icin kullandigi  double[] dizisini return eder
     * @return double[]
     */
    public double[] return_double_array() {

        return polynom;
    }

    
    
    /**
     * Parametre olarak aldigi indexe n degerini atayarak set eder
     *
     * @param s-int
     * @param n-double
     */
    public void setIndex(int s, double n) {

        if(s>=0 && s<=getSize()-1)
        polynom[s] = n;
        
        else
            System.out.printf("Yanlis indexi degistirmeye calisiyorsunuz!\n");
    }

    
    
    /**
     *Polynomun toplam katsayi sayisini yani derecesini ayni zamanda member olarak kullandigi double[] dizisinin 
     * buyuklugunu return eder.
     * @return int
     */
    public int getSize() {
        return psize;
    }

    
    
    /**Parametre olarak aldigi coef degerinden polynomial objesi olusturur
     * (2.0,4) parametreleri ile cagrilmasi sonucunda olusturacagi obje 2x3 + 0x2 + 0x1 + 0
     *
     * @param c-double
     * @param size-size
     */
    public polynomial(double c, int size) {
        polynom = new double[size];

        for (int i = 0; i < size; ++i) {
            if (i == 0) {
                polynom[i] = c;
            } else {
                polynom[i] = 0.0;
            }
        }

        psize = size;
    }

    
    
    /**
     *double[] olarak aldigi double referans arrayinden polynomial objesi olusturan constructor
     * @param _polynom-double[]
     */
    public polynomial(double[] _polynom) {

        polynom = new double[_polynom.length];

        psize = _polynom.length;

        for (int i = 0; i < _polynom.length; ++i) {

            polynom[i] = _polynom[i];
        }

    }

    
    
    /**
     *Parametre olarak aldigi polynomial objesini asil obje ile toplayarak return eder.
     * @param other-polynomial
     * @return polynomial
     */
    public polynomial Add(polynomial other) {

        if (other.getSize() > getSize()) {

            double[] temp = new double[other.getSize()];

            for (int i = 0; i < other.getSize(); ++i) {
                temp[i] = other.getIndex(i);

            }

            int j = temp.length - 1;

            for (int i = getSize() - 1; i >= 0; --i) {
                temp[j] += getIndex(i);
                --j;
            }

            polynomial temppolynomial = new polynomial(temp);
            return temppolynomial;

        } else {

            double[] temp = new double[getSize()];

            for (int j = 0; j < getSize(); ++j) {
                temp[j] = getIndex(j);
            }

            int j = temp.length - 1;
            for (int k = other.getSize() - 1; k >= 0; --k) {

                temp[j] += other.getIndex(k);
                --j;
            }
            polynomial temppolynomial = new polynomial(temp);
            return temppolynomial;
        }

    }

    
    
    /**
     *Parametre olarak aldigi polynomial objesini asil objeden cikartir ve return eder
     *
     * @param other-polynomial
     * @return polynomial
     */
    public polynomial Subs(polynomial other) {

        polynomial temp = new polynomial(other.polynom);

        for (int i = 0; i < temp.getSize(); ++i) {
            temp.setIndex(i, temp.getIndex(i) * (-1));

        }

        return this.Add(temp);
    }

    
    
    /**
     *Polynomial objelerini matematiksel kurala gore carpar ve return eder
     * sirasiyla katsayilari carparken her bir carpma sonucunda bir polynom olusturur ve her polynomu birbirine ekler
     * @param other-polynomial
     * @return polynomial
     */
    public polynomial Multiply(polynomial other) {

        double[] temp = new double[(getSize()) + (other.getSize() - 1)];

        for (int i = 0; i < (getSize()) + (other.getSize() - 1); ++i) {
            temp[i] = 0.0;
        }

        polynomial temppoly = new polynomial(temp);

        for (int i = 0; i < getSize(); ++i) {
            for (int j = 0; j < other.getSize(); ++j) {
                polynomial temp2 = new polynomial((getIndex(i) * other.getIndex(j)), (getSize() - i) + (other.getSize() - j - 1));
                temppoly = temppoly.Add(temp2);
            }
        }

        return temppoly;
    }

    
    
    /**
     * Parametre olarak aldigi deger ile polynomun degerini hesaplar ve return eder
     *
     * @param param-double
     * @return double
     */
    public double evaluate(double param) {

        double temp = 0.0;
        int j = 0;
        for (int i = getSize() - 1; i >= 0; --i) {
            temp += getIndex(i) * Math.pow(param, j);
            ++j;
        }

        return temp;
    }

    
    
    /**Polynomial objesinin memberlarina gore ekranda ifade edilis bicimini string formatina cevirir
     *
     * @return String
     */
    @Override
    public String toString() {

        String temp = String.format("%.1fX^%d", getIndex(0), getSize() - 1);

        for (int i = 1; i < getSize() - 1; ++i) {

            if (getIndex(i) >= 0) {
                temp = String.format("%s + %.1fX^%d", temp, getIndex(i), getSize() - i - 1);
            } else {
                temp = String.format("%s %.1fX^%d", temp, getIndex(i), getSize() - i - 1);
            }
        }

        if (getIndex(getSize() - 1) >= 0) {
            temp = String.format("%s  + %.1f", temp, getIndex(getSize() - 1));
        } else {
            temp = String.format("%s %.1f", temp, getIndex(getSize() - 1));
        }

        return temp;

    }

    
    
    /**
     *Oncelikle gelen objenin polynomial objesi olup olmadigini kontrol eder
     * Sonrasinda gelen objeyi polynomial tipini cast eder ve butun katsayilari kontrol karsilastirir.
     * @param obj-Object
     * @return boolean
     */
    @Override
    public boolean equals(Object obj) {

        if (!(obj instanceof polynomial)) {
            return false;
        }

        polynomial temp = (polynomial) obj;

        if (temp.getSize() != getSize()) {
            return false;
        }

        for (int i = 0; i < getSize(); ++i) {
            if (getIndex(i) != temp.getIndex(i)) {
                return false;
            }
        }

        return true;
    }

}

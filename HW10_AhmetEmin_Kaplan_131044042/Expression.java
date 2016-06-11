/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw10_ahmetemin_kaplan_131044042;

/**
 *
 * @author aek
 */
public class Expression {

    private Expression[] AllExpressions;

    private int sizeofExpression;

    public int getSize() {
        return sizeofExpression;
    }

    public Expression() {
    }

    /*
     * 
     * @param _E
     *  Oncelikle parametre olarak aldigi expression referans dizisi uzerindeki sag ve sol parantez sayilarinin esitligine gore
     Hata durumunda exception firlatmaktadir
     Ek olarak iki operand veya iki operator ard arda gelme durumunda da exception firlatir
     */
    Expression(Expression[] _E) throws Exception {
   
            int LeftParantesis = 0;

            int RigthParantesis = 0;
            Paranthesis tempP;

            for (int i = 0; i < _E.length; ++i) {
                if (_E[i] instanceof Paranthesis) {
                    tempP = (Paranthesis) _E[i];
                    if (tempP.getParanthesisType() == '(') {
                        ++LeftParantesis;
                    } else {
                        ++RigthParantesis;
                    }
                }
            }

            if (LeftParantesis != RigthParantesis) {
                throw new WrongElements();
            }




            int operandQ = 0;
            int operatorQ = 0;

            for (int t = 0; t < _E.length; ++t) {
                if (_E[t] instanceof Operand) {
                    ++operandQ;
                } else if (_E[t] instanceof Operators) {
                    --operandQ;
                }
                if (operandQ != 1 && operandQ != 0) {
                    throw new WrongElements();
                }
            }



        AllExpressions = new Expression[_E.length];

        for (int i = 0; i < _E.length; ++i) {
            AllExpressions[i] = _E[i];
        }
        sizeofExpression = _E.length;
    }

    /**
     *
     *
     * @return Operand 
     * 
     * Expressionlarin sonucunu islem onceligine gore hesaplayan
     * metoddur. Oncelikle ifadedeki paranteze yonelir parantezin baslangic
     * indexi ile bitis indexi arasindaki expressionlar Yeni bir expression
     * objesine initialize edilerek recursive cagri yapilir Parantez ifadeleri
     * hesaplandiktan sonra islem onceligine uygun olarak carpma ve bolme
     * islemlerini yapar ardindan toplama ve cikarma islemlerine yonelir.Butun
     * operasyonlarin sonucununda ortaya cikacak tek kalan operand return edilir.
     */
    public Operand Evaluate() throws Exception{

        
        /*BASE CASE*/
        
        if (getSize() == 3) {

            Operand temp;

            Operand tempOperand1, tempOperand2;

            Operators tempOperator;

            tempOperand1 = (Operand) AllExpressions[0];

            tempOperand2 = (Operand) AllExpressions[2];

            tempOperator = (Operators) AllExpressions[1];

          
                if (tempOperator.getoperatorType() == '*') {
                    int x = tempOperand1.getOperand() * tempOperand2.getOperand();
                    temp = new Operand(x);
                    sizeofExpression = 1;
                    return temp;
                } else if (tempOperator.getoperatorType() == '+') {
                    int x = tempOperand1.getOperand() + tempOperand2.getOperand();
                    temp = new Operand(x);
                    sizeofExpression = 1;
                    return temp;

                } else if (tempOperator.getoperatorType() == '-') {
                    int x = tempOperand1.getOperand() - tempOperand2.getOperand();
                    temp = new Operand(x);
                    sizeofExpression = 1;
                    return temp;
                } else if (tempOperator.getoperatorType() == '/') {
                    if (tempOperand2.getOperand() == 0) {
                        throw new DivideByZero();
                    }
                    int x = tempOperand1.getOperand() / tempOperand2.getOperand();
                    temp = new Operand(x);
                    sizeofExpression = 1;
                    return temp;
                }

        } else {

            int beginindex = -1;
            int finishindex = -1;
            for (int k = 0; k < getSize(); ++k) {
                if (AllExpressions[k] instanceof Paranthesis) {
                    Paranthesis temporary = (Paranthesis) AllExpressions[k];
                    if (temporary.getParanthesisType() == '(') {
                        int now = 0;
                        int hedef = 1;
                        beginindex = k;

                        /*Parantezin icindeki islemin baslangic ve bitis indexleri hesaplanir*/
                        
                        for (int l = k + 1; l < getSize(); ++l) {
                            if (AllExpressions[l] instanceof Paranthesis) {
                                Paranthesis temp5 = (Paranthesis) AllExpressions[l];
                                if (temp5.getParanthesisType() == ')') {
                                    ++now;

                                } else if (temp5.getParanthesisType() == '(') {
                                    ++hedef;
                                }

                                if (now == hedef) {
                                    finishindex = l;
                                    l = getSize();
                                }

                            }
                        }
                      /*  5 + ( 2 + 4 )
                        0 1 2 3 4 5 6     */   

                        /*Parantezin icindeki islemin sonucu 1 operand olacagi icin ifademiz kucultulur */
                        /* Ornegin 3+(2+1)+5 icin ifademiz 3+ParantezinIcindekiİsleminSonucu+5  haline getirilir*/
                        Expression[] tempexp = new Expression[getSize() - (finishindex - beginindex )];
                        int z;
                        for (z = 0; z < beginindex; ++z) {
                            tempexp[z] = AllExpressions[z];
                        }

                        /*Parantezin basladigi indexe parantezin icindeki islemin sonuc operandi atanir tabiki bu atama icin oncelikle
                        Parantezin icindeki islemin sonucunun recursive call ile hesaplanmasi gerekmektedir */
                        if (z == beginindex) {
                            Expression[] tmp = new Expression[finishindex - beginindex - 1];
                            int p = 0;
                            Operand tempoperand;
                            Operators tempoperator;

                            Operand tempoperand3;
                            Operators tempoperator3;

                            Paranthesis tempParanthesis;
                            Paranthesis tempParanthesis3;

                            for (int i = beginindex + 1; i < finishindex; ++i) {
                                if (AllExpressions[i] instanceof Operators) {
                                    tempoperator = (Operators) AllExpressions[i];
                                    tempoperator3 = new Operators(tempoperator.getoperatorType());
                                    tmp[p] = tempoperator3;
                                } else if (AllExpressions[i] instanceof Operand) {
                                    tempoperand = (Operand) AllExpressions[i];
                                    tempoperand3 = new Operand(tempoperand.getOperand());
                                    tmp[p] = tempoperand3;
                                } else if (AllExpressions[i] instanceof Paranthesis) {
                                    tempParanthesis = (Paranthesis) AllExpressions[i];
                                    tempParanthesis3 = new Paranthesis(tempParanthesis.getParanthesisType());
                                    tmp[p] = tempParanthesis3;
                                }

                                ++p;
                            }

                            Expression tmp9 = new Expression(tmp);
                            
                            /*Recursive cagri burada yapilir ve bu cagrinin sonucu kucultulmus arrayde gerekli indexe atanir*/
                            
                            tempexp[z] = tmp9.Evaluate();

                            ++z;
                        }

                        
                        for (int m = finishindex + 1; m < getSize(); ++m) {
                            tempexp[z] = AllExpressions[m];
                            ++z;
                        }
                        AllExpressions = tempexp;
                        sizeofExpression = sizeofExpression - (finishindex - beginindex);
                        --k;
                    }
                }

            }
            //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
            //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
            //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
            /*Islem onceligi mantigina gore parantezlerin ici hesaplandiktan sonra carpma ve bolme islemleri yapilmalidir*/
            /*    3+2*5-1   ifadesi  3+CarpmaIslemininSonucu-1 seklin bir ifadeye donusecegi icin arrayimiz kucultulur    */
            /* Carpma islemi icin yeniden Recursive cagri yapilir */
            for (int k = 0; k < getSize(); ++k) {
                
                if (AllExpressions[k] instanceof Operators) {
                    Operators temporary = (Operators) AllExpressions[k];
                    if (temporary.getoperatorType() == '/' || temporary.getoperatorType() == '*') {
                        beginindex = k - 1;
                        finishindex = k + 1;
                        Expression[] tempexp = new Expression[getSize() - 2];
                        int z;
                        for (z = 0; z < beginindex; ++z) {
                            tempexp[z] = AllExpressions[z];
                        }

                        if (z == beginindex) {
                            Expression[] tmp = new Expression[3];

                            Operand tmpoperand = (Operand) AllExpressions[beginindex];
                            Operand tmp2operand = new Operand(tmpoperand.getOperand());

                            tmp[0] = tmp2operand;

                            Operators tmpoperator = (Operators) AllExpressions[beginindex + 1];
                            Operators tmp2operator = new Operators(tmpoperator.getoperatorType());
                            tmp[1] = tmp2operator;

                            tmpoperand = (Operand) AllExpressions[beginindex + 2];
                            tmp2operand = new Operand(tmpoperand.getOperand());
                            tmp[2] = tmp2operand;

                            Expression tmp9 = new Expression(tmp);
                            tempexp[z] = tmp9.Evaluate();

                            ++z;
                        }

                        for (int m = finishindex + 1; m < getSize(); ++m) {
                            tempexp[z] = AllExpressions[m];
                            ++z;
                        }
                        AllExpressions = tempexp;
                        sizeofExpression = sizeofExpression - 2;
                        --k;
                    }
                }

            }
            //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@q
            //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@q
            //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@q
            /*Toplama ve cikarma islemlerinin onceligi en dusuk onceliktir fakat bu operasyonlarin hesaplanmasi durumuda*/
            /*Carpma ve bolmeden cok farkl degildir yani yeniden array kucultulur ve Recursive cagri yapilir*/
            for (int k = 0; k < getSize(); ++k) {
                if (AllExpressions[k] instanceof Operators) {
                    Operators temporary = (Operators) AllExpressions[k];
                    if (temporary.getoperatorType() == '+' || temporary.getoperatorType() == '-') {
                        beginindex = k - 1;
                        finishindex = k + 1;
                        Expression[] tempexp = new Expression[getSize() - 2];
                        int z;
                        for (z = 0; z < beginindex; ++z) {
                            tempexp[z] = AllExpressions[z];
                        }

                        if (z == beginindex) {
                            Expression[] tmp = new Expression[3];

                            Operand tmpoperand = (Operand) AllExpressions[beginindex];
                            Operand tmp2operand = new Operand(tmpoperand.getOperand());

                            tmp[0] = tmp2operand;

                            Operators tmpoperator = (Operators) AllExpressions[beginindex + 1];
                            Operators tmp2operator = new Operators(tmpoperator.getoperatorType());
                            tmp[1] = tmp2operator;

                            tmpoperand = (Operand) AllExpressions[beginindex + 2];
                            tmp2operand = new Operand(tmpoperand.getOperand());
                            tmp[2] = tmp2operand;

                            Expression tmp9 = new Expression(tmp);
                            tempexp[z] = tmp9.Evaluate();

                            ++z;
                        }

                        for (int m = finishindex + 1; m < getSize(); ++m) {
                            tempexp[z] = AllExpressions[m];
                            ++z;
                        }
                        AllExpressions = tempexp;
                        sizeofExpression = sizeofExpression - 2;
                        --k;
                    }
                }

            }

            //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@q
            //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@q
            //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@q
        }

        return (Operand) AllExpressions[0];

    }

    
/**
 * 
 * @return String
 */
    @Override
    public String toString() {

        String Estring = AllExpressions[0].toString();

        for (int i = 1; i < getSize(); ++i) {
            Estring = String.format("%s%s", Estring, AllExpressions[i].toString());
        }

        return Estring;
    }

    
    /**
     * 
     * @param obj
     * @return boolean
     * Parametre olarak aldigi objenin oncelikle Expression sinifinin uyesi olup olmadigini kontrol eder
     * Ardindan Expression ifadesinin gerekli cast islemini yaptiktan sonra sahip oldugu expression referans dizisinin
     * indexlerini tek tek polymorphic cagri ile kontrol eder eger memberlar ayni ise true farkli ise false return eder
     */
    @Override
    public boolean equals(Object obj) {

        if (obj instanceof Expression) {
            Expression temp;
            temp = (Expression) obj;
            if (getSize() != temp.getSize()) {
                System.out.printf("1\n");
                return false;
            } else {
                for (int i = 0; i < getSize(); ++i) {
                    if (!(AllExpressions[i].equals(temp.AllExpressions[i]))) {
                        return false;
                    }
                }

                return true;
            }

        } else {
            return false;
        }

    }

}

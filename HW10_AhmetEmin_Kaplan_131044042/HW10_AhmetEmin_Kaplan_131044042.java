/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw10_ahmetemin_kaplan_131044042;

import java.util.Scanner;

/**
 *
 * @author aek
 *///Programin main metodu kullanicidan her bir expression icin her seferinde string olarak okuma yapar
//Okunan stringleri gerekli parcalama islemleriyle expresion ifadelerine donusturur
//Bu hususta girilen input dogru oldugu surece program ic ice parantezler dahil butun
//Operasyonlari hesaplar

//Exception handling

public class HW10_AhmetEmin_Kaplan_131044042 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        try {

            Scanner input = new Scanner(System.in);

            Expression[] myExpression = new Expression[1];
            Expression[] tempExpression;
            String tempstring;
            int i = 0;

            do {

                System.out.printf("Enter your expression element!\n");
                tempstring = input.nextLine();

                if (tempstring.compareTo("=") != 0) {
                    if (tempstring.length() > 1) {
                        if (i > 0) {
                            tempExpression = new Expression[i + 1];
                            for (int y = 0; y < myExpression.length; ++y) {
                                tempExpression[y] = myExpression[y];
                            }
                            myExpression = tempExpression;
                        }
                        myExpression[i] = new Operand(Integer.parseInt(tempstring));
                        ++i;
                    } else if (tempstring.charAt(0) == '+' || tempstring.charAt(0) == '-' || tempstring.charAt(0) == '*' || tempstring.charAt(0) == '/' || tempstring.charAt(0) == '(' || tempstring.charAt(0) == ')') {
                        if (i > 0) {
                            tempExpression = new Expression[i + 1];
                            for (int y = 0; y < myExpression.length; ++y) {
                                tempExpression[y] = myExpression[y];
                            }
                            myExpression = tempExpression;
                        }

                        if (tempstring.charAt(0) == '(' || tempstring.charAt(0) == ')') {
                            myExpression[i] = new Paranthesis(tempstring.charAt(0));
                        } else {
                            myExpression[i] = new Operators(tempstring.charAt(0));
                        }

                        ++i;
                    } else {
                        if (i > 0) {
                            tempExpression = new Expression[i + 1];
                            for (int y = 0; y < myExpression.length; ++y) {
                                tempExpression[y] = myExpression[y];
                            }
                            myExpression = tempExpression;
                        }
                        myExpression[i] = new Operand(Integer.parseInt(tempstring));
                        ++i;
                    }
                }

            } while (tempstring.compareTo("=") != 0);

            Expression Process = new Expression(myExpression);

            System.out.printf("%s\n", Process);

            System.out.printf("Result is %d\n", Process.Evaluate().getOperand());

                 //Equals metodu icin test asamasi
            //
            Operand o1 = new Operand(5);

            Operand o2 = new Operand(5);

            Operand o3 = new Operand(4);

            Operand o4 = new Operand(4);

            Operators op1 = new Operators('+');

            Operators op2 = new Operators('+');

            Paranthesis p1 = new Paranthesis('(');

            Paranthesis p2 = new Paranthesis(')');

            Paranthesis p3 = new Paranthesis('(');

            Paranthesis p4 = new Paranthesis(')');

            Expression[] deneme1 = new Expression[5];

            deneme1[0] = p1;
            deneme1[1] = o1;
            deneme1[2] = op1;
            deneme1[3] = o3;
            deneme1[4] = p2;

            Expression[] deneme2 = new Expression[5];

            deneme2[0] = p3;
            deneme2[1] = o2;
            deneme2[2] = op2;
            deneme2[3] = o4;
            deneme2[4] = p4;

            Expression e1 = new Expression(deneme1);
            Expression e2 = new Expression(deneme2);

            if (e1.equals(e2)) {
                System.out.printf("%s  ile  %s birbirine esittir\n", e1, e2);
            } else {
                System.out.printf("%s  ile  %s birbirine esit degildir\n", e1, e2);
            }

                    /////////////////////////////
            deneme2[2] = new Operators('-');

            Expression e3 = new Expression(deneme2);

            if (e1.equals(e3)) {
                System.out.printf("%s  ile  %s birbirine esittir\n", e1, e3);
            } else {
                System.out.printf("%s  ile  %s birbirine esit degildir\n", e1, e3);
            }

        } catch (Exception exp) {
            if (exp instanceof DivideByZero) {
                System.out.printf("DividebyZero exception!\n");
                System.exit(2);
            }

            if (exp instanceof WrongElements) {
                System.out.printf("WrongElements exception!\n");
                System.exit(1);
            }
        }

    }

}

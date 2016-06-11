/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw09_ahmetemin_kaplan_131044042;

/**
 *
 * @author aek
 */
public class HW09_AhmetEmin_Kaplan_131044042 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here

        double []k1={4.0 , -7.0 , 3.0};
        double []k2={4.0 , -7.0 , 3.0};
        double []k3={3.0 , 4.0 , 5.0 , -2.0};
        double []k4={-1.0 , 2.5 , 4.0 , 6.0};
        double []k5={6.0 , -3.0 , 0.0};
      
        
        polynomial p1= new polynomial(k1);
        
        polynomial p2= new polynomial(k2);
        
        polynomial p3= new polynomial(k3);
        
        polynomial p4= new polynomial(k4);
        
        polynomial p5= new polynomial(k5);
        
        polynomial p6,p7;
        
        System.out.printf(" p1---> %s\n p2---> %s\n p3---> %s\n p4---> %s\n p5---> %s\n\n\n\n",p1,p2,p3,p4,p5);
        
        /* Add metodu icin test asamasi*/
 
        System.out.printf("(((()))))ADD METODU ICIN TEST ((((()))))\n\n");
 
        System.out.printf(" p1+p2 ---> %s \n\n", p1.Add(p2));
        
        System.out.printf(" p2+p3 ---> %s \n\n", p2.Add(p3));
        
        System.out.printf(" p3+p4 ---> %s \n\n", p3.Add(p4));
        
        System.out.printf(" p4+p5 ---> %s \n\n", p4.Add(p5));
        
        System.out.printf(" p2+p3 ---> %s \n\n", p2.Add(p3));
         
        System.out.printf(" p2+p5 ---> %s \n\n", p2.Add(p5));
        
        System.out.printf(" p3+p1 ---> %s \n\n\n\n\n\n", p3.Add(p1));
   

        /*Subs metodu icin test asamasi*/
        System.out.printf("(((()))))SUBS METODU ICIN TEST ((((()))))\n\n");
        
            System.out.printf(" p3-p3 ---> %s \n\n", p3.Subs(p3));
         System.out.printf(" p3-p4 ---> %s \n\n", p3.Subs(p4));
        
        System.out.printf(" p4-p5 ---> %s \n\n", p4.Subs(p5));
        
        System.out.printf(" p2-p3 ---> %s \n\n", p2.Subs(p3));
         
        System.out.printf(" p2-p5 ---> %s \n\n", p2.Subs(p5));
        
        System.out.printf(" p3-p1 ---> %s \n\n\n\n\n\n", p3.Subs(p1));
   
       
        
        System.out.printf("(((()))))MULTIPLY METODU ICIN TEST ((((()))))\n\n");
        
        System.out.printf(" p3*p3 ---> %s \n\n", p3.Multiply(p3));
        
        System.out.printf(" p3*p4 ---> %s \n\n", p3.Multiply(p4));
        
        System.out.printf(" p4*p5 ---> %s \n\n", p4.Multiply(p5));
        
        System.out.printf(" p2*p3 ---> %s \n\n", p2.Multiply(p3));
         
        System.out.printf(" p2*p5 ---> %s \n\n\n\n\n\n", p2.Multiply(p5));
        
        
        System.out.printf("(((()))))EVALUATE METODU ICIN TEST ((((()))))\n\n");
        System.out.printf("P1(%.1f)= %.1f\n\n",2.0,p1.evaluate(2.0));
        System.out.printf("P2(%.1f)= %.1f\n\n",3.0,p2.evaluate(3.0));
        System.out.printf("P3(%.1f)= %.1f\n\n",4.0,p3.evaluate(4.0));
        System.out.printf("P4(%.1f)= %.1f\n\n",3.0,p4.evaluate(3.0));
        System.out.printf("P5(%.1f)= %.1f\n\n",2.0,p5.evaluate(2.0));
        
        
        
        
        System.out.printf("(((()))))EQUALS METODU ICIN TEST ((((()))))\n\n");
        
        
  
        if(p1.equals(p2))
        {
            System.out.printf("p1 polinomu p2 polinomuna ESITTIR!\n");
        }
        else{
            System.out.printf("p1 polinomu p2 polinomuna ESIT DEGILDIR!\n");
        }
    
    
        
        
        if(p2.equals(p3))
        {
            System.out.printf("p2 polinomu p3 polinomuna ESITTIR!\n");
        }
        else{
            System.out.printf("p2 polinomu p3 polinomuna ESIT DEGILDIR!\n");
        }
    
    
        if(p3.equals(p5))
        {
            System.out.printf("p3 polinomu p5 polinomuna ESITTIR!\n");
        }
        else{
            System.out.printf("p3 polinomu p5 polinomuna ESIT DEGILDIR!\n");
        }
    
    
        if(p4.equals(p2))
        {
            System.out.printf("p4 polinomu p2 polinomuna ESITTIR!\n");
        }
        else{
            System.out.printf("p4 polinomu p2 polinomuna ESIT DEGILDIR!\n");
        }
    
    
        
        
        
        
        
    
    }
    
}

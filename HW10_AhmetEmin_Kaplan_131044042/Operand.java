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
public class Operand extends Expression{
    
    private int op;

    /**
     * 
     * @return int 
     */
    public int getOperand(){
        return op;
    }
    
    /**
     * 
     * @param t-int 
     */
    public Operand(int t) {
        op=t;
    }

    /**
     * 
     * @return String 
     */
    @Override
    public String toString() {
        return String.format("%d",getOperand());
    }

    /**
     * 
     * @param obj object
     * @return boolean
     */
    @Override
    public boolean equals(Object obj) {
    
        if(obj instanceof Operand)
        {
        
            Operand temp=(Operand)obj;
            
            if(temp.getOperand()!=getOperand())
                return false;
            
            else 
                return true;
        }
    
        else
            return false;
    }
    
    
    
}

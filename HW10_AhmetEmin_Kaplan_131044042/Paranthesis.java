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
public class Paranthesis extends Expression{
    
    private char ParanthesisType;
    
    /**
     * 
     * @param p-char 
     */
    Paranthesis(char p)
    {
        ParanthesisType=p;
    }

    /**
     * 
     * @return char 
     */
    public char getParanthesisType() {
        return ParanthesisType;
    }

    /**
     * 
     * @return String 
     */
    @Override
    public String toString() {
        return String.format("%c",getParanthesisType());
    }

    /**
     * 
     * @param obj-object
     * @return boolean
     */
    @Override
    public boolean equals(Object obj) {
    
        if(obj instanceof Paranthesis)
        {
            Paranthesis temp;
            temp=(Paranthesis)obj;
            
            if(temp.getParanthesisType()!=getParanthesisType())
            {
                return false;
            }
            else
                return true;
        }
    
    
        else
            return false;
    }
    
    
    
}

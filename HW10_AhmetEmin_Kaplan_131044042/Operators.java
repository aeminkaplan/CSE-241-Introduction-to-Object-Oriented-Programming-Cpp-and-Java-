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
public class Operators extends Expression{
    
    private char operatorType;

    /**
     * 
     * @return char 
     */
    
    public char getoperatorType()
    {
        return operatorType;
    }
    
    /**
     * 
     * @param type-char 
     */
    
    Operators(char type) {
        operatorType=type;
    }

    /**
     * 
     * @return String 
     */
    @Override
    public String toString() {
        return String.format("%c",getoperatorType());
    }
    
    /**
     * 
     * @param obj-object
     * @return boolean
     */
    @Override
    public boolean equals(Object obj) {
       
        if(obj instanceof Operators)
        {
           Operators temp;
           temp=(Operators) obj;
            
           if(getoperatorType()!=temp.getoperatorType())
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

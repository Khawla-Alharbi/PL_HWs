
package myscanner;

// @author Khawla

import java.io.File;
import java.util.Scanner;

public class MyScanner {
    enum types {VAR_CODE, ASSIGN_OP, MULTIPLY_OP, DIGIT_CODE,
                MINUS_OP, SUM_OP, SEMICOLON}; 
    public static void Scan(String tokens){
            types tokentype;
            int i=0;
            boolean flag= false;
            while(i<tokens.length()){
                char token = tokens.charAt(i);
                String newToken="";
                
                if(token >='0' && token<='9'){
                tokentype=types.DIGIT_CODE;
                while(token!=32){
                newToken+=token;
                i++;
                token = tokens.charAt(i);
                if(token == ';'){flag = true; break;}
                }
                System.out.println(newToken +" is a "+tokentype);
                }else if(token == '+'){
                    tokentype= types.SUM_OP;
                System.out.println(token +" is a "+tokentype);
                }else if(token == '-'){
                    tokentype= types.MINUS_OP;
                System.out.println(token +" is a "+tokentype);
                }else if(token == '='){
                    tokentype= types.ASSIGN_OP;
                System.out.println(token +" is an "+tokentype);
                }else if(token == '*'){
                    tokentype= types.MULTIPLY_OP;
                System.out.println(token +" is a "+tokentype);
                }else if(token == ';'){
                    tokentype= types.SEMICOLON;
                System.out.println(token +" is a "+tokentype);
                }else if(token != 32){
                    tokentype= types.VAR_CODE;
                    while(token!=32){
                    newToken+=token;
                    i++;
                    if(i>=tokens.length()){break;}
                    token = tokens.charAt(i);
                    if(token == ';'){flag = true; break;}
                }
                    System.out.println(newToken +" is a "+tokentype);
                    
                }
                    
                if(flag){
                    System.out.println("; is a SEMICOLON");                 
                    flag=false;
                }
                i++;
            }
           
    }
    public static void main(String[] args) throws Exception {
         File file = new File("C:\\Users\\Khawl\\Desktop\\Tokens File.txt");
         Scanner sc = new Scanner(file);
         
            String lineOfTokens;
            do{
                lineOfTokens = sc.nextLine();
                System.out.println("Tokens: " + lineOfTokens);
                Scan(lineOfTokens);
                System.out.println("----------------------------------");
            }while(sc.hasNext());


    }
    
}

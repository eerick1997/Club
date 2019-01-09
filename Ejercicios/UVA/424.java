import java.util.*;
import java.math.*;

//Write Main instead of integer_inquiry
public class integer_inquiry{

    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        BigInteger sum = new BigInteger("0");
        while(true){
            BigInteger n = scanner.nextBigInteger();
            if(n.equals(BigInteger.ZERO)){
                System.out.println(sum);
                return;
            }
            sum = sum.add(n);
            
        }        
    }
}
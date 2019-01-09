import java.util.*;
import java.math.*;

public class greatFactorial{

    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        while(scanner.hasNextBigInteger()){
            int number = scanner.nextInt();
            System.out.println(number + "!\n" + factorial(number));
        }
        
    }

    public static BigInteger factorial(int number){
        BigInteger value = new BigInteger("1");
        for(int i = 2; i <= number; i++){
            value = value.multiply(new BigInteger(i + ""));
        }
        return value;
    }
}
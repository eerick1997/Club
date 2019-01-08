import java.util.*;
import java.math.*;

//Write Main instead of very_easy
public class very_easy{

    public static void main(String args[]){

        Scanner scanner = new Scanner(System.in);
        while(scanner.hasNextInt()){
            BigInteger R = new BigInteger("0");
            int N = scanner.nextInt();
            BigInteger A = scanner.nextBigInteger();
            
            for(int i = 1; i <= N; i++){
                BigInteger element = A.pow(i);
                element = element.multiply( new BigInteger(i + "") );
                R = R.add( element );
            }
            System.out.println(R);
        }
        

    }
}
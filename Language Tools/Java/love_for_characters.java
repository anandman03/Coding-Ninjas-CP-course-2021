import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
        int size = in.nextInt();
        String s = in.next();
        
        int countA = 0;
        int countS = 0;
        int countP = 0;
        
        for(int i = 0;i < size; i++){
            if(s.charAt(i) == 'a')
                countA++;
            else if(s.charAt(i) == 's')
                countS++;
            else if(s.charAt(i) == 'p')
                countP++;
        }
        
        System.out.print(countA);
        System.out.print(" ");
		System.out.print(countS);
        System.out.print(" ");
        System.out.print(countP);
	}
}
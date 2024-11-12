
public class RandomDice {
    public static void main(String[] args) {
        int num1, num2;
        do {
            num1 = (int)(Math.random() * 6) + 1;
            num2 = (int)(Math.random() * 6) + 1;
            if (num1 + num2 == 5) {
                System.out.printf("합이 5인 수의 쌍: %d, %d\n", num1, num2);
            }
        } while (num1 + num2 != 5);
    }
}

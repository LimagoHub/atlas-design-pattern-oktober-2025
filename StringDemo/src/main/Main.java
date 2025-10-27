package main;

import java.time.Duration;
import java.time.Instant;

public class Main {

    public static void main(String[] args) {
        StringBuilder sb = new StringBuilder("");


        Instant start = Instant.now();
        for (int i = 0; i < 2_000_000; i++) {
            sb.append("A");
        }
        String s = sb.toString();
        Instant end = Instant.now();
        System.out.println("Duration = " + Duration.between(start, end).toMillis());
    }
}

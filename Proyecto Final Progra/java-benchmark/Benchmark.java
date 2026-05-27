import java.io.FileWriter;
import java.util.HashMap;
import java.util.TreeMap;

public class Benchmark {

    public static void run() {

        try {

            FileWriter out =
                new FileWriter(
                    "java_results.csv"
                );

            out.write(
                "language,operation,structure,records,time_ms\n"
            );

            int RECORDS = 10000;

            // =========================
            // HASHMAP INSERT
            // =========================

            HashMap<Integer, Student>
                hashMap =
                    new HashMap<>();

            long start1 =
                System.nanoTime();

            for(int i = 0; i < RECORDS; i++) {

                hashMap.put(
                    i,
                    new Student(
                        i,
                        "Student"
                    )
                );
            }

            long end1 =
                System.nanoTime();

            double insertHash =
                (end1 - start1)
                / 1000000.0;

            out.write(
                "Java,insert,HashMap,"
                + RECORDS
                + ","
                + insertHash
                + "\n"
            );

            // =========================
            // HASHMAP SEARCH
            // =========================

            long start2 =
                System.nanoTime();

            for(int i = 0; i < RECORDS; i++) {

                hashMap.get(i);
            }

            long end2 =
                System.nanoTime();

            double searchHash =
                (end2 - start2)
                / 1000000.0;

            out.write(
                "Java,search,HashMap,"
                + RECORDS
                + ","
                + searchHash
                + "\n"
            );

            // =========================
            // TREEMAP INSERT
            // =========================

            TreeMap<Integer, Student>
                treeMap =
                    new TreeMap<>();

            long start3 =
                System.nanoTime();

            for(int i = 0; i < RECORDS; i++) {

                treeMap.put(
                    i,
                    new Student(
                        i,
                        "Student"
                    )
                );
            }

            long end3 =
                System.nanoTime();

            double insertTree =
                (end3 - start3)
                / 1000000.0;

            out.write(
                "Java,insert,TreeMap,"
                + RECORDS
                + ","
                + insertTree
                + "\n"
            );

            // =========================
            // TREEMAP TRAVERSAL
            // =========================

            long start4 =
                System.nanoTime();

            treeMap.values();

            long end4 =
                System.nanoTime();

            double traversal =
                (end4 - start4)
                / 1000000.0;

            out.write(
                "Java,traversal,TreeMap,"
                + RECORDS
                + ","
                + traversal
                + "\n"
            );

            out.close();

            System.out.println(
                "java_results.csv generado"
            );

        } catch(Exception e) {

            System.out.println(e);
        }
    }
}
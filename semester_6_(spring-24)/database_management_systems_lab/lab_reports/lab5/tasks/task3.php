<!-- Task 5.3: Write PHP script that shows the division table displayed as in Table 5.2 using different loops. 
For each number, display whether that number is an odd or even number, and also display a 
message if the number is a prime number. -->

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>5.3: Division Table</title>
    <style>
        table, th, td {
            border: 1px solid black;
            border-collapse: collapse;
            padding: 5px;
            text-align: center;
        }
    </style>
</head>
<body>
    <h1>Task 5.3: Division Table</h1>

    <table>
        <tr>
            <th>/</th>
            <?php for ($i = 1; $i <= 10; $i++): ?>
                <th><?= $i ?></th>
            <?php endfor; ?>
        </tr>

        <?php
        function is_prime($num) {
            if ($num < 2) return false;
            for ($i = 2; $i <= sqrt($num); $i++) {
                if ($num % $i == 0) return false;
            }
            return true;
        }

        function classify_number($num) {
            $type = fmod($num, 2) == 0 ? "even" : "odd";
            $prime = is_prime($num) ? "and prime" : "";
            return "{$type} {$prime}";
        }

        for ($row = 1; $row <= 10; $row++) {
            echo "<tr>";
            echo "<th>$row</th>";
            for ($col = 1; $col <= 10; $col++) {
                $result = $row / $col;
                // Check if the result is an integer, if so, classify it
                if (intval($result) == $result) {
                    $description = classify_number($result);
                } else {
                    $description = ""; // Do not classify non-integers
                }
                $formattedResult = round($result, 3);
                echo "<td>{$formattedResult} {$description}</td>";
            }
            echo "</tr>";
        }
        ?>

    </table>
</body>
</html>

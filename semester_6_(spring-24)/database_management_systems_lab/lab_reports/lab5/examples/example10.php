<!-- Example 10: Using foreach to Loop through Keys and Values  -->
 
<?php 
    $myBook = array( "title" => "The Grapes of Wrath","author" => "John Steinbeck","pubYear" => 1939 ); 
    foreach ( $myBook as $key => $value ) { 
        echo " < dt > $key < /dt > "; 
        echo " < dd > $value < /dd > "; 
    } 
?> 

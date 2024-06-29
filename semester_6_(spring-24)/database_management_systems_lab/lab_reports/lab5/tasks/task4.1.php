<!-- A class is a blueprint for creating objects, providing initial values for state (member variables) and implementations of behavior (member functions or methods). -->
<?php
class Car {
    // Properties
    public $color;
    public $model;

    // Constructor
    public function __construct($color, $model) {
        $this->color = $color;
        $this->model = $model;
    }

    // Method
    public function getDetails() {
        return $this->color . " " . $this->model;
    }
}

// Creating an object
$myCar = new Car("red", "Toyota");
echo $myCar->getDetails(); // Outputs: red Toyota
?>

# Cpp-project

## Contents

### (Product Inventory)
The goal of this project is to create an application that manages an inventory of products. To this end, you need to write a C++ program having two
central components:
1. A product class which represents the products that you need to manage: A product has a name, an id, a quantity on hand, and two locations
block and roof.
2. The product class should allow several operations such as: setters, getters, and locate its place.
3. Furthermore, the products are classified into two types:
∗ Liquid products which are characterized by the amount in Liters, the price per liter, and a flammable flag.The liquid products should enable the following functions: getters, setters, calculateTotalPrice and isFlammable.
∗ Solid products which are characterized by the number of pieces, the price per piece, and a fragile flag. The solid products should enable the following functions: getters, setters, calculateTotalPrice and isFlammable.

### (An inventory class)
Which keeps track of various products. This class should have:
1. A list of products. 
2. The following operations:
*A private function load that loads the data from the local files
to inventory list of products
*A private function save that saves the products list to a disk
∗ A function removeProduct to remove a specific product according
to its id.
∗ A function add to add a new product to the inventory
∗ A function getNewId to get an available id according to the items
in the list
∗ A function getProductCount to get the count of a specific product
in the inventory
∗ A function getUnitCount to get the sum of the quantities of all
items
∗ A function getInventoryValue to get the total price of the inventory items
∗ A function clearInventory to remove all the items from the inventory

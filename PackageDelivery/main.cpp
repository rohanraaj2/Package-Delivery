#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "node.hpp"
#include "truck.hpp"
#include <fstream>
#include <string>

using namespace std;

BSTNode* root = NULL; // this is the root of BST
ofstream MyFile("Trip.txt"); //this is the file where the output BST in ascending order would be saved.


// defined all the functions below

string specific_line(int i)
{  //This function returns a specific line from the input text file.
    string r_line;
    fstream r_file("Input.txt");
    for (int j = 1; j <= i; j++)
    {
        getline(r_file, r_line);
    }
    return r_line;
}


BSTNode* insert_node(BSTNode* root_node, Truck* node)
{  //this function inserts a new node in the BST having a root node.
    
    BSTNode *n_obj = new BSTNode;// defining it outside of if block so that it can be deleted later on easily.
    if(root_node == nullptr){    //if a null pointer is obtained than a new object's poiner of type BST is created, and assigned to that node.
        n_obj -> val = (*node);
        n_obj -> left = nullptr;
        n_obj -> right = nullptr;
        root_node = n_obj;
        return root_node;
    }

    else if( ((root_node -> val).get_regNo()) > (node -> get_regNo()) ){  //if root value of regisration is number is greater than the node's (to be inserted) values than function is called with root's left as its new root.
        root_node -> left = insert_node(root_node -> left, node);
    }

    else if( ((root_node -> val).get_regNo()) < (node -> get_regNo()) ){  //if root value of regisration is number is lesser than the node's (to be inserted) values than function is called with root's right as its new root.
        root_node -> right = insert_node(root_node -> right, node);    
    }

    delete n_obj;
    return root_node;
}


BSTNode* loadTrucks()
{    //It implements the code for construction of BST.
    std::string line;
    ifstream file1("Input.txt");
    int c = 0;
    while(getline(file1, line))
    {
       c+=1;
    } 
    BSTNode* root_node;  //root of BST
    BSTNode* n_obj = new BSTNode;

    for (int i = 1; i <= c; i += 5)
    {  //this loop iterated over each entry(as one entry consist of 5 lines.)

        Truck obj (specific_line(i), stod( specific_line(i+1)), specific_line(i+2), stoi( specific_line(i+3)),stoi( specific_line(i+4) ) );

        if (i==1){     //this condition assigns only first entry as root node of BST.
            n_obj -> val = obj;
            n_obj -> left = nullptr;
            n_obj -> right = nullptr;
            root_node = n_obj;

        }
        else {
            root_node = insert_node(root_node, &obj);  //continuosly inserting and updating the BST.
        }
    }

    delete n_obj;
    return root_node;
}



void makeJourney(BSTNode* node)
{  //this traverses through the BST and make the required changes once the journey has been made.
    if (node == NULL){
        return;
    }
    makeJourney(node -> left);
    (node -> val).calculate(); //it actually calculates the changes after the trip.
    makeJourney(node -> right);

}

void writefile(BSTNode* node)
{      //it writes on the output text file.

    //writing in the file.
    MyFile << (node -> val).get_driver() << (node -> val).get_petrol() << "\n" << (node -> val).get_regNo() << "\n" << (node -> val).get_fullMileage() << "\n" << (node -> val).get_emptyMileage() << "\n";

}

void unloadTrucks(BSTNode* node)
{  //It simply saves the nodes in ascending order in the file. 
    if(node == NULL){
        return;
    }
        unloadTrucks(node -> left);

        writefile(node);

        unloadTrucks(node -> right);
}


int main()
{
    BSTNode* root = new BSTNode;
    root=loadTrucks();   //saving the root node from load Truck so that it can be used by later functions in the code easily to 
    makeJourney(root);
    unloadTrucks(root);
    MyFile.close();
    delete root;
    return 0;
}

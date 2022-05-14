//
//  tests.cpp
//

#define CATCH_CONFIG_RUNNER
#define CATCH_CONFIG_CONSOLE_WIDTH 150

#include <iostream>
#include "BST.h"
#include "catch.hpp"
#include "PrettyPrinter.h"



/* **************************************************************** */
/* **************************************************************** */


void makeBST(BST<int> & tree, int arr[], int arrSize) {
    for (int i=0; i < arrSize; i++) {
        tree.insert(arr[i]);
    }
}


/* **************************************************************** */
/* **************************************************************** */


void findPredecessorTestSetup(BST<int> & tree, std::stringstream & setupInfo) {
    int arr[] = {50, 75, 25, 10, 5, 1, 6, 26, 60, 51, 65, 69};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    makeBST(tree, arr, arrSize);
    
    std::stringstream ss;
    PrettyPrinter::printPretty(tree.root, 1, 0, ss);
    setupInfo << "inserted values 50, 75, 25, 10, 5, 1, 6, 26, 60, 51, 65, 69\n";
    const char *treeString = "\n"
        "                ______________50______________\n"
        "               /                              \\\n"
        "        ______25______                  ______75      \n"
        "       /              \\                /               \n"
        "    __10              26            __60__                \n"
        "   /                               /      \\                \n"
        "  _5                              51      65                \n"
        " /  \\                                       \\                \n"
        " 1   6                                      69                \n";
    setupInfo << "before calling findPredecessor(n), BST should be: " << treeString << "\n";
    setupInfo << "Your BST is: " << ss.str() << "\n";
    setupInfo << "before calling findPredecessor(n), BST numNodes should be 12";
    INFO(setupInfo.str());
    REQUIRE(tree.numNodes == 12);
}


void findNodeIterativelyTestSetup(BST<int> & tree, std::stringstream & setupInfo) {
    int arr[] = {50, 75, 25, 10, 5, 1, 6, 26, 60, 51, 65, 69};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    makeBST(tree, arr, arrSize);
    
    std::stringstream ss;
    PrettyPrinter::printPretty(tree.root, 1, 0, ss);
    INFO("inserted values 50, 75, 25, 10, 5, 1, 6, 26, 60, 51, 65, 69");
    const char *treeString = "\n"
    "                ______________50______________\n"
    "               /                              \\\n"
    "        ______25______                  ______75      \n"
    "       /              \\                /               \n"
    "    __10              26            __60__                \n"
    "   /                               /      \\                \n"
    "  _5                              51      65                \n"
    " /  \\                                       \\                \n"
    " 1   6                                      69                \n";
    setupInfo << "before calling findNodeIteratively(n,x), BST should be: " << treeString << "\n";
    setupInfo << "Your BST is: " << ss.str() << "\n";
    setupInfo << "before calling findNodeIteratively(n,x), BST numNodes should be 12";
    INFO(setupInfo.str());
    REQUIRE(tree.numNodes == 12);
}


void heightTestSetupNoNodes(BST<int> & tree, std::stringstream & setupInfo) {
    std::stringstream ss;
    PrettyPrinter::printPretty(tree.root, 1, 0, ss);
    setupInfo << "before calling height(root), BST should be empty\n";
    setupInfo << "Your BST is: " << ss.str() << "\n";
    INFO(setupInfo.str());
}


void heightTestSetup1Node(BST<int> & tree, std::stringstream & setupInfo) {
    int arr[] = {50};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    makeBST(tree, arr, arrSize);
    
    std::stringstream ss;
    PrettyPrinter::printPretty(tree.root, 1, 0, ss);
    INFO("inserted value 50");
    const char *treeString = "\n"
    "50\n";
    setupInfo << "before calling height(root), BST should be: " << treeString << "\n";
    setupInfo << "Your BST is: " << ss.str() << "\n";
    INFO(setupInfo.str());
}


void heightTestSetupTallLeftOutsideDescendant(BST<int> & tree, std::stringstream & setupInfo) {
    int arr[] = {50, 75, 25, 10, 5, 1, 26, 60, 51, 65};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    makeBST(tree, arr, arrSize);
    
    std::stringstream ss;
    PrettyPrinter::printPretty(tree.root, 1, 0, ss);
    INFO("inserted values 50, 75, 25, 10, 5, 1, 26, 60, 51, 65");
    const char *treeString = "\n"
    "                ______________50______________\n"
    "               /                              \\\n"
    "        ______25______                  ______75      \n"
    "       /              \\                /               \n"
    "    __10              26            __60__                \n"
    "   /                               /      \\                \n"
    "  _5                              51      65                \n"
    " /                                                        \n"
    " 1                                                       \n";
    setupInfo << "before calling height(root), BST should be: " << treeString << "\n";
    setupInfo << "Your BST is: " << ss.str() << "\n";
    INFO(setupInfo.str());
}


void heightTestSetupTallLeftInsideDescendant(BST<int> & tree, std::stringstream & setupInfo) {
    int arr[] = {50, 75, 25, 10, 5, 26, 27, 30, 31, 60, 51, 65, 69};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    makeBST(tree, arr, arrSize);
    
    std::stringstream ss;
    PrettyPrinter::printPretty(tree.root, 1, 0, ss);
    INFO("inserted values 50, 75, 25, 10, 5, 26, 27, 30, 31, 60, 51, 65, 69");
    const char *treeString = "\n"
    "                                ______________________________50______________________________\n"
    "                               /                                                              \\\n"
    "                ______________25______________                                  ______________75              \n"
    "               /                              \\                                /                               \n"
    "        ______10                              26______                  ______60______                                \n"
    "       /                                              \\                /              \\                                \n"
    "       5                                              27__            51              65__                                \n"
    "                                                          \\                               \\                                \n"
    "                                                          30                              69                                \n"
    "                                                            \\                                                                \n"
    "                                                            31                                                                \n";
    setupInfo << "before calling height(root), BST should be: " << treeString << "\n";
    setupInfo << "Your BST is: " << ss.str() << "\n";
    INFO(setupInfo.str());
}


void heightTestSetupTallRightOutsideDescendant(BST<int> & tree, std::stringstream & setupInfo) {
    int arr[] = {50, 75, 25, 10, 26, 60, 80, 90};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    makeBST(tree, arr, arrSize);
    
    std::stringstream ss;
    PrettyPrinter::printPretty(tree.root, 1, 0, ss);
    INFO("inserted values 50, 75, 25, 10, 26, 60, 80, 90");
    const char *treeString = "\n"
    "        ______50______\n"
    "       /              \\\n"
    "    __25__          __75__\n"
    "   /      \\        /      \\\n"
    "  10      26      60      80\n"
    "                            \\\n"
    "                            90\n";
    setupInfo << "before calling height(root), BST should be: " << treeString << "\n";
    setupInfo << "Your BST is: " << ss.str() << "\n";
    INFO(setupInfo.str());
}


void heightTestSetupTallRightInsideDescendant(BST<int> & tree, std::stringstream & setupInfo) {
    int arr[] = {50, 75, 25, 10, 26, 60, 80, 55, 58, 57};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    makeBST(tree, arr, arrSize);
    
    std::stringstream ss;
    PrettyPrinter::printPretty(tree.root, 1, 0, ss);
    INFO("inserted values 50, 75, 25, 10, 26, 60, 80, 55, 58, 57");
    const char *treeString = "\n"
    "                                ______________________________50______________________________\n"
    "                               /                                                              \\\n"
    "                ______________25______________                                  ______________75______________\n"
    "               /                              \\                                /                              \\\n"
    "              10                              26                        ______60                              80      \n"
    "                                                                       /                                               \n"
    "                                                                      55__                                                \n"
    "                                                                          \\                                                \n"
    "                                                                          58                                                \n"
    "                                                                         /                                                   \n"
    "                                                                        57                                                    \n";
    setupInfo << "before calling height(root), BST should be: " << treeString << "\n";
    setupInfo << "Your BST is: " << ss.str() << "\n";
    INFO(setupInfo.str());
}


void heightTestSetupNullLeftChild(BST<int> & tree, std::stringstream & setupInfo) {
    int arr[] = {1, 2, 3, 4};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    makeBST(tree, arr, arrSize);
    
    std::stringstream ss;
    PrettyPrinter::printPretty(tree.root, 1, 0, ss);
    INFO("inserted values 1, 2, 3, 4");
    const char *treeString = "\n"
    "               1______\n"
    "                      \\\n"
    "                       2__\n"
    "                          \\\n"
    "                           3\n"
    "                            \\\n"
    "                             4\n";
    setupInfo << "before calling height(root), BST should be: " << treeString << "\n";
    setupInfo << "Your BST is: " << ss.str() << "\n";
    INFO(setupInfo.str());
}


void heightTestSetupNullRightChild(BST<int> & tree, std::stringstream & setupInfo) {
    int arr[] = {3, 2, 1};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    makeBST(tree, arr, arrSize);
    
    std::stringstream ss;
    PrettyPrinter::printPretty(tree.root, 1, 0, ss);
    INFO("inserted values 3, 2, 1");
    const char *treeString = "\n"
    "    ___3  \n"
    "   /       \n"
    "  _2        \n"
    " /           \n"
    " 1            \n";
    setupInfo << "before calling height(root), BST should be: " << treeString << "\n";
    setupInfo << "Your BST is: " << ss.str() << "\n";
    INFO(setupInfo.str());
}


/* **************************************************************** */
/* **************************************************************** */


// 1 point
TEST_CASE("verify that findPredecessor(n) returns nullptr when node has no predecessor (node has no children)", "[FINDPREDECESSOR][11]") {
    BST<int> tree;
    std::stringstream setupInfo;
    findPredecessorTestSetup(tree, setupInfo);
    INFO(setupInfo.str());
    Node<int> *node51 = tree.findNodeIteratively(tree.root, 51);
    INFO("should fail to find a predecessor for node 51 and return nullptr");
    REQUIRE(tree.findPredecessor(node51) == nullptr);
}


// 1 point
TEST_CASE("verify that findPredecessor(n) returns nullptr when node has no predecessor (node has only right children)", "[FINDPREDECESSOR][12]") {
    BST<int> tree;
    std::stringstream setupInfo;
    findPredecessorTestSetup(tree, setupInfo);
    INFO(setupInfo.str());
    Node<int> *node65 = tree.findNodeIteratively(tree.root, 65);
    INFO("should fail to find a predecessor for node 65 and return nullptr");
    REQUIRE(tree.findPredecessor(node65) == nullptr);
}


// 3 points
TEST_CASE("verify that findPredecessor(n) returns correct node when predecessor is left child", "[FINDPREDECESSOR][13]") {
    BST<int> tree;
    std::stringstream setupInfo;
    findPredecessorTestSetup(tree, setupInfo);
    INFO(setupInfo.str());
    Node<int> *node60 = tree.findNodeIteratively(tree.root, 60);
    INFO("should successfully find a predecessor for node 60 and return node containing value 51");
    REQUIRE(tree.findPredecessor(node60)->data == 51);
}


// 3 points
TEST_CASE("verify that findPredecessor(n) returns correct node when predecessor is down right branch of left child", "[FINDPREDECESSOR][14]") {
    BST<int> tree;
    std::stringstream setupInfo;
    findPredecessorTestSetup(tree, setupInfo);
    INFO(setupInfo.str());
    Node<int> *node75 = tree.findNodeIteratively(tree.root, 75);
    INFO("should successfully find a predecessor for node 75 and return node containing value 69");
    REQUIRE(tree.findPredecessor(node75)->data == 69);
}


/* **************************************************************** */
/* **************************************************************** */


// 1 points
TEST_CASE("verify that findNodeIteratively(n,x) returns nullptr when BST is empty", "[FINDNODEITERATIVELY][21]") {
    BST<int> tree;
    INFO("before calling findNodeIteratively(n,x), BST should be empty [ root -> nullptr ]");
    REQUIRE(tree.root == nullptr);
    INFO("before calling findNodeIteratively(n,x), BST numNodes should be 0");
    REQUIRE(tree.numNodes == 0);
    INFO("attempted to find a node containing the value 11");
    REQUIRE(tree.findNodeIteratively(nullptr, 11) == nullptr);
}


// 1 point
TEST_CASE("verify that findNodeIteratively(root,x) returns nullptr when BST does not contain x", "[FINDNODEITERATIVELY][22]") {
    BST<int> tree;
    std::stringstream setupInfo;
    findNodeIterativelyTestSetup(tree, setupInfo);
    INFO(setupInfo.str());
    INFO("should fail to find a node containing the value 49");
    REQUIRE(tree.findNodeIteratively(tree.root, 49) == nullptr);
}


// 1 point
TEST_CASE("verify that findNodeIteratively(root, x) returns correct node when BST contains x in the root node", "[FINDNODEITERATIVELY][23]") {
    BST<int> tree;
    std::stringstream setupInfo;
    findNodeIterativelyTestSetup(tree, setupInfo);
    INFO(setupInfo.str());
    INFO("should successfully find a node containing the value 50");
    REQUIRE(tree.findNodeIteratively(tree.root, 50)->data == 50);
}


// 1 point
TEST_CASE("verify that findNodeIteratively(root,x) returns correct node when BST contains x in a leaf node", "[FINDNODEITERATIVELY][24]") {
    BST<int> tree;
    std::stringstream setupInfo;
    findNodeIterativelyTestSetup(tree, setupInfo);
    INFO(setupInfo.str());
    INFO("should successfully find a node containing the value 69");
    REQUIRE(tree.findNodeIteratively(tree.root, 69)->data == 69);
}


// 1 point
TEST_CASE("verify that findNodeIteratively(root, x) returns correct node when BST contains x in a middle node with two children", "[FINDNODEITERATIVELY][25]") {
    BST<int> tree;
    std::stringstream setupInfo;
    findNodeIterativelyTestSetup(tree, setupInfo);
    INFO(setupInfo.str());
    INFO("should successfully find a node containing the value 25");
    REQUIRE(tree.findNodeIteratively(tree.root, 25)->data == 25);
}


// 1 point
TEST_CASE("verify that findNodeIteratively(root, x) returns correct node when BST contains x in a middle node with single left child", "[FINDNODEITERATIVELY][26]") {
    BST<int> tree;
    std::stringstream setupInfo;
    findNodeIterativelyTestSetup(tree, setupInfo);
    INFO(setupInfo.str());
    INFO("should successfully find a node containing the value 75");
    REQUIRE(tree.findNodeIteratively(tree.root, 75)->data == 75);
}


// 1 point
TEST_CASE("verify that findNodeIteratively(root, x) returns correct node when BST contains x in a middle node with single right child", "[FINDNODEITERATIVELY][27]") {
    BST<int> tree;
    std::stringstream setupInfo;
    findNodeIterativelyTestSetup(tree, setupInfo);
    INFO(setupInfo.str());
    INFO("should successfully find a node containing the value 65");
    REQUIRE(tree.findNodeIteratively(tree.root, 65)->data == 65);
}


// 1 point
TEST_CASE("verify that findNodeIteratively(m,x) returns correct node when search starts at m and BST contains x in a leaf node", "[FINDNODEITERATIVELY][28]") {
    BST<int> tree;
    std::stringstream setupInfo;
    findNodeIterativelyTestSetup(tree, setupInfo);
    INFO(setupInfo.str());
    INFO("should successfully find a node containing the value 6 starting from node 25");
    Node<int> *node = tree.findNodeIteratively(tree.root, 25);
    REQUIRE(tree.findNodeIteratively(node, 6)->data == 6);
}


// 1 point
TEST_CASE("verify that findNodeIteratively(m,x) returns nullptr when search starts at m and BST contains x in a higher node", "[FINDNODEITERATIVELY][29]") {
    BST<int> tree;
    std::stringstream setupInfo;
    findNodeIterativelyTestSetup(tree, setupInfo);
    INFO(setupInfo.str());
    INFO("should fail to find a node containing the value 50 when starting from node 25");
    Node<int> *node = tree.findNodeIteratively(tree.root, 25);
    REQUIRE(tree.findNodeIteratively(node, 50) == nullptr);
}


/* **************************************************************** */
/* **************************************************************** */


// 1 point
TEST_CASE("verify that height(root) returns 0 when called on an empty tree", "[HEIGHT][31]") {
    BST<int> tree;
    std::stringstream setupInfo;
    heightTestSetupNoNodes(tree, setupInfo);
    INFO(setupInfo.str());
    INFO("height method should return 0");
    REQUIRE(tree.height(tree.root) == 0);
}


// 1 point
TEST_CASE("verify that height(root) returns 1 when called on a tree of height 1", "[HEIGHT][32]") {
    BST<int> tree;
    std::stringstream setupInfo;
    heightTestSetup1Node(tree, setupInfo);
    INFO(setupInfo.str());
    INFO("height method should return 1");
    REQUIRE(tree.height(tree.root) == 1);
}


// 1 point
TEST_CASE("verify that height(root) returns correct value when left side is taller (outside descendant)", "[HEIGHT][33]") {
    BST<int> tree;
    std::stringstream setupInfo;
    heightTestSetupTallLeftOutsideDescendant(tree, setupInfo);
    INFO(setupInfo.str());
    INFO("height method should return 5");
    REQUIRE(tree.height(tree.root) == 5);
}


// 1 point
TEST_CASE("verify that height(root) returns correct value when left side is taller (inside descendant)", "[HEIGHT][34]") {
    BST<int> tree;
    std::stringstream setupInfo;
    heightTestSetupTallLeftInsideDescendant(tree, setupInfo);
    INFO(setupInfo.str());
    INFO("height method should return 6");
    REQUIRE(tree.height(tree.root) == 6);
}


// 1 point
TEST_CASE("verify that height(root) returns correct value when right side is taller (outside descendant)", "[HEIGHT][35]") {
    BST<int> tree;
    std::stringstream setupInfo;
    heightTestSetupTallRightOutsideDescendant(tree, setupInfo);
    INFO(setupInfo.str());
    INFO("height method should return 4");
    REQUIRE(tree.height(tree.root) == 4);
}


// 1 point
TEST_CASE("verify that height(root) returns correct value when right side is taller (inside descendant)", "[HEIGHT][36]") {
    BST<int> tree;
    std::stringstream setupInfo;
    heightTestSetupTallRightInsideDescendant(tree, setupInfo);
    INFO(setupInfo.str());
    INFO("height method should return 6");
    REQUIRE(tree.height(tree.root) == 6);
}


// 1 point
TEST_CASE("verify that height(root) returns correct value when root node has null left child", "[HEIGHT][37]") {
    BST<int> tree;
    std::stringstream setupInfo;
    heightTestSetupNullLeftChild(tree, setupInfo);
    INFO(setupInfo.str());
    INFO("height method should return 4");
    REQUIRE(tree.height(tree.root) == 4);
}


// 1 point
TEST_CASE("verify that height(root) returns correct value when root node has null right child", "[HEIGHT][38]") {
    BST<int> tree;
    std::stringstream setupInfo;
    heightTestSetupNullRightChild(tree, setupInfo);
    INFO(setupInfo.str());
    INFO("height method should return 3");
    REQUIRE(tree.height(tree.root) == 3);
}


/* **************************************************************** */
/* **************************************************************** */



/* **************************************************************** */
/* **************************************************************** */
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
/* **************************************************************** */
/* **************************************************************** */


int main( int argc, char const* const* const argv )
{
    // global setup...
    std::cout << BOLDCYAN << std::endl;
    std::cout << "###############################################################################" << std::endl;
    std::cout << "############################# Running Unit Tests ##############################" << std::endl;
    std::cout << "###############################################################################" << std::endl;
    std::cout << RESET << std::endl;

    int result = Catch::Session().run( argc, argv );

    // global clean-up...
    std::cout << BOLDCYAN << std::endl;
    std::cout << "###############################################################################" << std::endl;
    std::cout << "########################### Done Running Unit Tests ###########################" << std::endl;
    std::cout << "###############################################################################" << std::endl;
    std::cout << RESET << std::endl;

    return result;
}

#include "BinarySearchTree.h"
#include "unit_test_framework.h"
#include <sstream>


TEST(test_BST_insert_size_and_height) {
	BinarySearchTree<int> tree;

	ASSERT_TRUE(tree.empty());
	ASSERT_EQUAL((int)tree.size(), 0);
	ASSERT_EQUAL((int)tree.height(), 0);
	
	tree.insert(2);
	tree.insert(4);
	ASSERT_EQUAL((int)tree.size(), 2);
	ASSERT_EQUAL((int)tree.height(), 2);

	tree.insert(1);
	ASSERT_EQUAL((int)tree.size(), 3);
	ASSERT_EQUAL((int)tree.height(), 2);
}

TEST(test_BST_traversing_inorder) {
	BinarySearchTree<int> arbol;

	arbol.insert(6);
	arbol.insert(4);
	arbol.insert(5);
	arbol.insert(1);
	arbol.insert(7);
	arbol.insert(10);

	std::ostringstream oss_inorder;
	arbol.traverse_inorder(oss_inorder);

	ASSERT_EQUAL(oss_inorder.str(), "1 4 5 6 7 10 ")
}

TEST(test_BST_traversing_preorder) {
	BinarySearchTree<int> arbol;

	arbol.insert(6);
	arbol.insert(4);
	arbol.insert(5);
	arbol.insert(1);
	arbol.insert(7);
	arbol.insert(10);

	std::ostringstream oss_preorder;
	tree.traverse_preorder(oss_preorder);
	ASSERT_EQUAL(oss_preorder.str(), "6 4 1 5 7 10 ")
}


TEST(test_BST_copy_using_constructor) {
	BinarySearchTree<int> arbol;

	arbol.insert(6);
	arbol.insert(4);
	arbol.insert(5);
	arbol.insert(1);
	arbol.insert(7);
	arbol.insert(10);

	// copy
	BinarySearchTree<int> tree(arbol);
	ASSERT_EQUAL((int)arbol.height(), (int)tree.height());
	ASSERT_EQUAL((int)arbol.size(), (int)tree.size());
	

	std::ostringstream oss_arbol;
	std::ostringstream oss_tree;
	arbol.traverse_inorder(oss_arbol);
	tree.traverse_inorder(oss_tree);

	ASSERT_EQUAL(oss_arbol.str(), oss_tree.str());

	tree.insert(2);

	ASSERT_NOT_EQUAL((int)arbol.size(), (int)tree.size());

	std::ostringstream oss_tree2;
	tree.traverse_inorder(oss_tree2);

	ASSERT_NOT_EQUAL(oss_tree.str(), oss_tree2.str());
}


TEST(test_BST_copy_using_assignment) {
	BinarySearchTree<int> arbol;

	arbol.insert(6);
	arbol.insert(4);
	arbol.insert(5);
	arbol.insert(1);
	arbol.insert(7);
	arbol.insert(10);

	// copy
	BinarySearchTree<int> tree = arbol;
	ASSERT_EQUAL((int)arbol.height(), (int)tree.height());
	ASSERT_EQUAL((int)arbol.size(), (int)tree.size());


	std::ostringstream oss_arbol;
	std::ostringstream oss_tree;
	arbol.traverse_inorder(oss_arbol);
	tree.traverse_inorder(oss_tree);

	ASSERT_EQUAL(oss_arbol.str(), oss_tree.str());

	tree.insert(2);

	ASSERT_NOT_EQUAL((int)arbol.size(), (int)tree.size());

	std::ostringstream oss_tree2;
	tree.traverse_inorder(oss_tree2);

	ASSERT_NOT_EQUAL(oss_tree.str(), oss_tree2.str());
}


TEST(test_BST_invariant) {
	BinarySearchTree<int> arbol;

	arbol.insert(6);
	arbol.insert(4);
	arbol.insert(5);
	arbol.insert(1);
	arbol.insert(7);
	arbol.insert(10);

	ASSERT_TRUE(arbol.check_sorting_invariant());

	auto i = arbol.begin();
	*i = 6;
	ASSERT_FALSE(arbol.check_sorting_invariant());
	
	*i = 1;
	ASSERT_TRUE(arbol.check_sorting_invariant());

	++++i;
	*i = 7;
	ASSERT_FALSE(arbol.check_sorting_invariant());
}

TEST(test_BST_min_and_max_function) {
	BinarySearchTree<int> arbol;

	arbol.insert(6);
	arbol.insert(4);
	arbol.insert(5);
	arbol.insert(1);
	arbol.insert(7);
	arbol.insert(10);

	ASSERT_EQUAL(*arbol.min_element(), 1);
	ASSERT_EQUAL(*arbol.max_element(), 10);

	ASSERT_EQUAL(*arbol.min_greater_than(1), 4);
	ASSERT_EQUAL(*arbol.min_greater_than(3), 4);
	ASSERT_EQUAL(*arbol.min_greater_than(5), 6);
	ASSERT_EQUAL(*arbol.min_greater_than(6), 7);
	ASSERT_EQUAL(*arbol.min_greater_than(8), 10);

	ASSERT_EQUAL(arbol.min_greater_than(10), arbol.end());
}
TEST_MAIN()

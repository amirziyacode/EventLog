# EventLogger

**EventLogger** is a C++ project for managing and storing events using a  
**Binary Search Tree (BST)** data structure.

The project allows efficient insertion, deletion, searching, and range-based queries on events.  
It also provides functionality to view the overall state of the tree and find the nearest event to a given key.

---

## Features

- Store events using a **Binary Search Tree (BST)**
- Insert a new event
- Delete an existing event
- Search for an event by key
- View overall tree status
- Find the **nearest event** to a given key
- Perform **range search** between two keys

---

## Data Structure

Each event is stored as a node in the Binary Search Tree.

Each node contains:

- `key` (used for ordering, e.g., timestamp or event ID)
- `data` (event information)
- `left` pointer
- `right` pointer

The tree is organized according to BST rules:
- Left subtree contains smaller keys
- Right subtree contains larger keys

---

## Core Operations

### 1) Insert
Adds a new event to the correct position in the BST.

### 2) Delete
Removes an event from the tree.  
Handles all standard BST deletion cases:
- Leaf node
- Node with one child
- Node with two children

### 3) Search
Finds and returns an event using its key.

### 4) Tree Status
Displays general information about the tree (such as traversal output, size, height, or structure).

### 5) Nearest Event
Finds the event whose key is closest to a given input key.

### 6) Range Search
Returns all events where:

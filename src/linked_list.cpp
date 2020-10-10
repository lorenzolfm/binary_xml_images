#include "linked_list.h"

template<typename T>
structures::LinkedList<T>::LinkedList() {
}

template<typename T>
structures::LinkedList<T>::~LinkedList() {
    clear();
}

template<typename T>
void structures::LinkedList<T>::clear() {
    while (!empty()) {
        pop_front();
    }
}

template<typename T>
void structures::LinkedList<T>::push_back(const T& data) {
    insert(data, size_);
}

template<typename T>
void structures::LinkedList<T>::push_front(const T& data) {
    Node* novo = new Node(data);
    if ( novo == nullptr ) {
        delete novo;
        throw(std::out_of_range("Erro lista cheia"));
    } else {
        novo->next(head);
        head = novo;
        size_++;
    }
}

template<typename T>
void structures::LinkedList<T>::insert(const T& data, std::size_t index) {
    Node* novo = new Node(data);
    Node* before;
    if ( novo == nullptr ) {
        throw(std::out_of_range("Erro Lista Cheia"));
    } else if (index > size_) {
        delete novo;
        throw(std::out_of_range("Erro Lista Cheia"));
    } else if (index == 0) {
        delete novo;
        push_front(data);
    } else {
        before = current(index);
        novo->next(before->next());
        before->next(novo);
        size_++;
    }
}

template<typename T>
void structures::LinkedList<T>::insert_sorted(const T& data) {
    if (empty()) {
        push_front(data);
    } else {
        Node* before = head;
        for (auto i = 0; i != size_; i++) {
            if (before->data() > data) {
                insert(data, i);
                break;
            } else if (i == size_ -1) {
                push_back(data);
                break;
            } else {
                before = before->next();
            }
        }
    }
}

template<typename T>
T& structures::LinkedList<T>::at(std::size_t index) {
    if (index > size_) {
        throw(std::out_of_range("Erro Lista Cheia"));
    } else if (empty()) {
        throw(std::out_of_range("Erro Lista vazia"));
    } else {
          Node* node = head;
          for (auto i = 0u; i != index; i++) {
              node = node->next();
          }
        return node->data();
    }
}

template<typename T>
T structures::LinkedList<T>::pop(std::size_t index) {
  Node *sai, *before;
  T dado;
  if (empty()) {
    throw("lista vazia");
    } else if (index < 0 || index > size_ -1) {
       throw(std::out_of_range("Erro Lista Cheia"));
    } else if (index == 0) {
      pop_front();
    } else {
    before = current(index);
    sai = before->next();
    before->next(sai->next());
    dado = sai->data();
    delete sai;
    size_--;
  }
    return dado;
}

template<typename T>
T structures::LinkedList<T>::pop_back() {
  Node *sai;
  if (empty()) {
    throw(std::out_of_range("Lista vazia"));
  } else {
    sai = end();
    T dado = sai->data();
    delete sai;
    size_--;
    return dado;
  }
}

template <typename T>
T structures::LinkedList<T>::pop_front() {
  if (empty())
    throw std::out_of_range("A lista está vazia");
  Node *remove = head;
  head = remove -> next();
  T data = remove -> data();
  size_--;
  delete remove;
  return data;
}

template <typename T>
void structures::LinkedList<T>::remove(const T& data) {
  pop(find(data));
}

template <typename T>
bool structures::LinkedList<T>::contains(const T& data) const {
  return find(data) < size();
}

template <typename T>
std::size_t structures::LinkedList<T>::find(const T& data) const {
  if(empty())
    throw std::out_of_range("A lista está vazia");
  Node *current= head;
  std::size_t i;
  for(i = 0; i < size(); i++) {
    if(current->data() == data) {
      return i;
    }
    current = current->next();
  }
  return i;
}

template <typename T>
bool structures::LinkedList<T>::empty() const {
  return size_ == 0;
}

template <typename T>
std::size_t structures::LinkedList<T>::size() const {
  return size_;
}

template class structures::LinkedList<std::string>;

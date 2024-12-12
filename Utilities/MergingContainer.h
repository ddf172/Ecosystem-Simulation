#ifndef RESOURCECONTAINER_H
#define RESOURCECONTAINER_H

#include <algorithm>
#include <iostream>
#include <vector>
#include "Simulation/Resources/Resource.h"
#include <type_traits>

template <typename T>
class MergingContainer {
    static_assert(std::is_base_of<Resource, typename std::remove_pointer<T>::type>::value, "T must be or derive from Resource");
    std::vector<T> data;
public:
    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;

    typename std::vector<T>::iterator begin();
    typename std::vector<T>::iterator end();
    typename std::vector<T>::const_iterator begin() const;
    typename std::vector<T>::const_iterator end() const;

    void operator+=(T item);
    std::vector<T>* getData();
};

template<typename T>
void MergingContainer<T>::operator+=(T item) {
    Resource* newResource = dynamic_cast<Resource*>(item);
    for(Resource* resource : this->data) {
        if(resource->getType() == newResource->getType()) {
            resource->setAmount(resource->getAmount() + newResource->getAmount());
            return;
        }
    }
    this->data.push_back(newResource);
}

template<typename T>
std::vector<T>* MergingContainer<T>::getData() {
    for (std::vector<Resource*>::iterator it = this->data.begin(); it != this->data.end();) {
        Resource* resource = dynamic_cast<Resource*>(*it);
        if(resource->getType() == MEAT && resource->getAmount() == 0) {
            delete resource;
            it = this->data.erase(it);
        }
        else {
            ++it;
        }
    }
    return &this->data;
}

template<typename T>
T& MergingContainer<T>::operator[](std::size_t index) {
    return data[index];
}

template<typename T>
const T& MergingContainer<T>::operator[](std::size_t index) const {
    return data[index];
}

template<typename T>
typename std::vector<T>::iterator MergingContainer<T>::begin() {
    return data.begin();
}

template<typename T>
typename std::vector<T>::iterator MergingContainer<T>::end() {
    return data.end();
}

template<typename T>
typename std::vector<T>::const_iterator MergingContainer<T>::begin() const {
    return data.begin();
}

template<typename T>
typename std::vector<T>::const_iterator MergingContainer<T>::end() const {
    return data.end();
}

#endif // RESOURCECONTAINER_H
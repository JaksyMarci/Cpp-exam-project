
#ifndef INDAPPER
#define INDAPPER

#include <vector>
#include <algorithm>


template<class Container, typename T = typename Container::value_type>



class index_appender_view{

    public:
    

    index_appender_view<Container, T>(){ 
  
    };

    index_appender_view<Container,T>(const index_appender_view<Container,T> &other) : v(other.v) 
    {   

    };

    void add(Container &cont){ 
        Container* mf = &cont; //&
        v.push_back(mf);

    } //ref hogy lehessen kivulrol valtoztatni
    
    int size() const{
        int sum = 0;

        for (Container* c_p : v){
            sum+=c_p->size();
        }
        
        return sum;
    }

    T &at( unsigned int index) const{ 

        bool b = true;
        
        int i = 0;
        while (b)

        {
            if (index + 1 > v[i]->size()){
                //következő container
                index = index - v[i]->size();
                i++;
                
            }
            else{
                b = false;
            }
        }

        return v[i]->at(index); 
    }

    T &operator[] (unsigned int index) const{

        bool b = true;
        
        int i = 0;
        while (b)

        {
            if (index + 1 > v[i]->size()){ 

                //következő container
                index = index - v[i]->size();

                i++;
 
            }
            else{
                b = false;
            }
        }

        return v[i]->at(index);

          
    }

    private:
    std::vector<Container*> v;
    
};

template<>

class index_appender_view<std::vector<bool>, bool>{
    public:
    

    index_appender_view<std::vector<bool>, bool>(){   
  
    };

    index_appender_view<std::vector<bool>,bool>(const index_appender_view<std::vector<bool>,bool> &other) : v(other.v) 
    {   

    };

    void add(std::vector<bool> &cont){ 
        std::vector<bool>* mf = &cont; //&
        v.push_back(mf);

    } //ref hogy lehessen kivulrol valtoztatni
    
    int size() const{
        int sum = 0;
        for (std::vector<bool>* c_p : v){
            sum+=c_p->size();
        
        }
        return sum;
    }

    std::vector<bool>::reference at(unsigned int index) const{ 

            bool b = true;
        
        int i = 0;
        while (b)

        {
            if (index + 1 > v[i]->size()){
                //következő container
                index = index - v[i]->size();
                i++;
                
            }
            else{
                b = false;
            }
        }

        return v[i]->at(index); 

    }

    std::vector<bool>::reference operator[] (unsigned int index) const{

                bool b = true;
        
        int i = 0;
        while (b)

        {
            if (index + 1 > v[i]->size()){
                //következő container
                index = index - v[i]->size();
                i++;
                
            }
            else{
                b = false;
            }
        }

        return v[i]->at(index); 

          
    }

    private:
    std::vector<std::vector<bool>*> v;
};

#endif



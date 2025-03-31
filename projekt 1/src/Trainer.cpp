#include "Trainer.h"

Trainer::Trainer(const std::string& name) : m_name(name), m_head(nullptr), m_tail(nullptr){}

Trainer::~Trainer(){
    TeamNode *current = m_head;
    while(current){
        current = m_head->next;
        delete m_head;
        m_head = current;
    }
}

void Trainer::addTeam(Team &team) {
    TeamNode *newNode = new TeamNode(team);
    if(!m_head){
        m_head = m_tail = newNode;
    }else{
        m_tail->next = newNode;
        newNode->prev = m_tail;
        m_tail = newNode;
    }
}

void Trainer::printTeams() const{
    TeamNode* current = m_head;
    std::cout << "Trainer: " << m_name << " teams:";
    while(current){
        std::cout << "\n- " << current->team.getName();
        current = current->next;
    }
    std::cout << "\n";
}
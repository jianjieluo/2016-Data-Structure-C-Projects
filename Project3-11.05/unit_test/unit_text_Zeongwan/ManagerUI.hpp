#ifndef MANAGERUI_HPP_
#define MANAGERUI_HPP_

#include "familyTreeManager.hpp"

class ManagerUI {
 public:
  ManagerUI();
  void OperationLoop(void);

 private:
  /**
   * constructor
   */
  void startManager(void);

  /**
   * catch user's operation
   * @return the operation
   */
  std::string getOperation();

  /**
   * execute the operation
   * @return if the operationloop continue
   */
  bool executeOperation(std::string t_operation);

  /**
   * quit the Manager
   */
  void quitManager(void);

  void createFamilyTree(void);

  /**
   * list all families Names, Names!!!
   */
  void listAllFamiles(void);
  /**
   * search meetings by title from storage
   */
  void queryMeetingByTitle(void);

  /**
   * search meetings by timeinterval from storage
   */
  void queryMeetingByTimeInterval(void);

  /**
   * delete meetings by title from storage
   */
  void deleteMeetingByTitle(void);

  /**
   * delete all meetings that this user sponsored
   */
  void deleteAllMeetings(void);

  /**
   * show the meetings in the screen
   */
  void printMeetings(std::list<Meeting> t_meetings);
  // dates
  std::string m_userName;
  std::string m_userPassword;
  AgendaService m_agendaService;
};

#endif

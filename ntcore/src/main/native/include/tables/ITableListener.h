// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#ifndef NTCORE_TABLES_ITABLELISTENER_H_
#define NTCORE_TABLES_ITABLELISTENER_H_

#include <memory>

#include <wpi/StringRef.h>
#include <wpi/deprecated.h>

#include "networktables/NetworkTableValue.h"

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#elif _WIN32
#pragma warning(push)
#pragma warning(disable : 4996)
#endif

class ITable;

/**
 * A listener that listens to changes in values in a {@link ITable}
 */
class WPI_DEPRECATED(
    "Use EntryListener, TableEntryListener, or TableListener as appropriate")
    ITableListener {
 public:
  virtual ~ITableListener() = default;
  /**
   * Called when a key-value pair is changed in a {@link ITable}
   * @param source the table the key-value pair exists in
   * @param key the key associated with the value that changed
   * @param value the new value
   * @param isNew true if the key did not previously exist in the table,
   * otherwise it is false
   */
  virtual void ValueChanged(ITable* source, wpi::StringRef key,
                            std::shared_ptr<nt::Value> value, bool isNew) = 0;

  /**
   * Extended version of ValueChanged.  Called when a key-value pair is
   * changed in a {@link ITable}.  The default implementation simply calls
   * ValueChanged().  If this is overridden, ValueChanged() will not be called.
   * @param source the table the key-value pair exists in
   * @param key the key associated with the value that changed
   * @param value the new value
   * @param flags update flags; for example, NT_NOTIFY_NEW if the key did not
   * previously exist in the table
   */
  virtual void ValueChangedEx(ITable* source, wpi::StringRef key,
                              std::shared_ptr<nt::Value> value,
                              unsigned int flags);
};

#ifdef __GNUC__
#pragma GCC diagnostic pop
#elif _WIN32
#pragma warning(pop)
#endif

#endif  // NTCORE_TABLES_ITABLELISTENER_H_

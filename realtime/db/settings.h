/* * Chai PCR - Software platform for Open qPCR and Chai's Real-Time PCR instruments.
 * For more information visit http://www.chaibio.com
 *
 * Copyright 2016 Chai Biotechnologies Inc. <info@chaibio.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>
#include <utility>
#include <iostream>
class Settings
{
public:
    Settings()
    {
        _debugMode = false;
        _wifiEnabled = false;
        _calibrationId = 0;
        _timeValid = false;

        resetDirtyStates();
    }

    inline void setDebugMode(bool mode) { _debugMode = mode; _debugModeDirtyState = true; }
    inline bool debugMode() const { return _debugMode; }
    inline bool isDebugModeDirty() const { return _debugModeDirtyState; }

    inline void setTimeZone(const std::string &zone) { _timeZone = zone; _timeZoneDirtyState = true; }
    inline void setTimeZone(std::string &&zone) { _timeZone = std::move(zone); _timeZoneDirtyState = true; }
    inline const std::string& timeZone() const { return _timeZone; }
    inline bool isTimeZoneDirty() const { return _timeZoneDirtyState; }

    inline void setWifiSsid(const std::string &zone) { _wifiSsid = zone; _wifiSsidDirtyState = true; }
    inline void setWifiSsid(std::string &&zone) { _wifiSsid = std::move(zone); _wifiSsidDirtyState = true; }
    inline const std::string& wifiSsid() const { return _wifiSsid; }
    inline bool isWifiSsidDirty() const { return _wifiSsidDirtyState; }

    inline void setWifiPassword(const std::string &password) { _wifiPassword = password; _wifiPasswordDirtyState = true; }
    inline void setWifiPassword(std::string &&password) { _wifiPassword = std::move(password); _wifiPasswordDirtyState = true; }
    inline const std::string& wifiPassword() const { return _wifiPassword; }
    inline bool isWifiSsidPassword() const { return _wifiPasswordDirtyState; }

    inline void setWifiEnabled(bool state) { _wifiEnabled = state; _wifiEnabledDirtyState = true; }
    inline bool wifiEnabled() const { return _wifiEnabled; }
    inline bool isWifiEnabledDirty() const { return _wifiEnabledDirtyState; }

    inline void setCallibrationId(int id) { _calibrationId = id; _calibrationIdDirtyState = true; }
    inline int calibrationId() const { return _calibrationId; }
    inline bool isCallibrationIdDirty() const { return _calibrationIdDirtyState; }

    inline void setTimeValid(bool state) { _timeValid = state; _timeValidDirtyState = true; }
    inline bool timeValid() const { return _timeValid; }
    inline bool isTimeValidDirty() const { return _timeValidDirtyState; }

    inline bool hasDirty() const
    {
        return _debugModeDirtyState ||
                _timeZoneDirtyState ||
                _wifiSsidDirtyState ||
                _wifiPasswordDirtyState ||
                _wifiEnabledDirtyState ||
                _calibrationIdDirtyState ||
                _timeValidDirtyState;
    }

    inline void resetDirtyStates()
    {
        _debugModeDirtyState = false;
        _timeZoneDirtyState = false;
        _wifiSsidDirtyState = false;
        _wifiPasswordDirtyState = false;
        _wifiEnabledDirtyState = false;
        _calibrationIdDirtyState = false;
        _timeValidDirtyState = false;
    }

private:
    bool _debugMode;
    bool _debugModeDirtyState;

    std::string _timeZone;
    bool _timeZoneDirtyState;

    std::string _wifiSsid;
    bool _wifiSsidDirtyState;

    std::string _wifiPassword;
    bool _wifiPasswordDirtyState;

    bool _wifiEnabled;
    bool _wifiEnabledDirtyState;

    int _calibrationId;
    bool _calibrationIdDirtyState;

    bool _timeValid;
    bool _timeValidDirtyState;
};

#endif // SETTINGS_H

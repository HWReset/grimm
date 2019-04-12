// Copyright 2019 The Beam Team
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "second_side.h"
#include "../base_transaction.h"
#include "bitcoin/bitcoin.hpp"
#include "common.h"

namespace beam::wallet
{
    class BitcoinSide : public SecondSide
    {
    public:
        BitcoinSide(BaseTransaction& tx, std::shared_ptr<BitcoinRPC> bitcoinRPC, bool isInitiator, bool isBtcOwner);

        bool Initial();
        void InitLockTime();
        bool HandleContract();
        bool SendRefund();
        bool SendRedeem();

    private:
        bool LoadSwapAddress();
        void InitSecret();
        libbitcoin::chain::script CreateAtomicSwapContract();
        bool SendExternalLockTx();
        void SendExternalTxDetails();
        bool BitcoinSide::RegisterExternalTx(const std::string& rawTransaction, SubTxID subTxID);
        bool ConfirmExternalLockTx();
        SwapTxState BuildLockTx();
        SwapTxState BitcoinSide::BuildWithdrawTx(SubTxID subTxID);
        void GetSwapLockTxConfirmations();
        bool SendExternalWithdrawTx(SubTxID subTxID);

        void OnGetRawChangeAddress(const std::string& response);
        void OnFundRawTransaction(const std::string& response);
        void OnSignLockTransaction(const std::string& response);
        void OnCreateWithdrawTransaction(const std::string& response);
        void OnDumpPrivateKey(SubTxID subTxID, const std::string& response);
        void OnGetSwapLockTxConfirmations(const std::string& response);

    private:
        BaseTransaction& m_tx;
        std::shared_ptr<BitcoinRPC> m_bitcoinRPC;
        bool m_isInitiator;
        bool m_isBtcOwner;

        // TODO: make a separate struct
        // btc additional params
        uint16_t m_SwapLockTxConfirmations = 0;
        boost::optional<std::string> m_SwapLockRawTx;
        boost::optional<std::string> m_SwapWithdrawRawTx;
    };

}
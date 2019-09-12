
#pragma once

#include "wallet/common.h"
#include "wallet/wallet_db.h"
#include "../base_transaction.h"

#include <condition_variable>
#include <boost/optional.hpp>
#include "utility/logger.h"
#include "asset_issue_tx_builder.h"

namespace grimm::wallet
{
    class BaseTxBuilder;

    class AssetIssueTransaction : public BaseTransaction
    {
        enum State : uint8_t
        {
            Initial,
            Invitation,
            PeerConfirmation,

            InvitationConfirmation,
            Registration,

            KernelConfirmation,
            OutputsConfirmation
        };
    public:
        static BaseTransaction::Ptr Create(INegotiatorGateway& gateway
                                    , IWalletDB::Ptr walletDB
                                    , IPrivateKeyKeeper::Ptr keyKeeper
                                    , const TxID& txID);
    private:
        AssetIssueTransaction(INegotiatorGateway& gateway
                        , IWalletDB::Ptr walletDB
                        , IPrivateKeyKeeper::Ptr keyKeeper
                        , const TxID& txID);
    private:
        TxType GetType() const override;
        void UpdateImpl() override;
        bool ShouldNotifyAboutChanges(TxParameterID paramID) const override;
        void SendInvitation(const AssetIssueTxBuilder& builder, bool isSender);
        void ConfirmInvitation(const AssetIssueTxBuilder& builder, bool sendUtxos);
        void ConfirmTransaction(const AssetIssueTxBuilder& builder, bool sendUtxos);
        void NotifyTransactionRegistered();
        bool IsSelfTx() const;
        State GetState() const;
    private:
        std::shared_ptr<AssetIssueTxBuilder> m_TxBuilder;
        grimm::AssetID _assetId;
        ECC::Scalar::Native _skAsset;
    };
}
